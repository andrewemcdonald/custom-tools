// Copyright (c) Andrew McDonald 2019. All rights reseved.

// dns.cc : Does a DNS lookup of the given hostname and service.
// (Essentially dig)

#include <arpa/inet.h>
#include <assert.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

using namespace std;

// Prints the given IPV4 address to stdout
void printV4Result(struct addrinfo *result);
// Prints the given IPV6 address to stdin
void printV6Result(struct addrinfo *result);

int main(int argc, char **argv) {
  if (argc != 2) {
    cout << "Usage: " << argv[0] << " [HOSTNAME]" << endl;
    return EXIT_FAILURE;
  }

  // Define hostname and service
  char *hostname = argv[1];

  // Setup hints and res
  struct addrinfo hints, *results;
  // Avoid sending garbage
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  // Do DNS lookup
  int res = getaddrinfo(hostname, nullptr, &hints, &results);
  if (res != 0) {
    cerr << "Error: DNS lookup failed." << endl;
    std::cerr << gai_strerror(res) << endl;
    return EXIT_FAILURE;
  }

  // Print results
  int i = 1;
  while (results != nullptr) {
    cout << "Result #" << i << endl;

    if (results->ai_family == AF_INET) {
      printV4Result(results);
    } else if(results->ai_family == AF_INET6) {
      printV6Result(results);
    } else {
      cout << "Unknown format." << endl;
    }

    results = results->ai_next;
    i++;
  }

  return EXIT_SUCCESS;
}

void printV4Result(struct addrinfo *result) {
  // For user readability
  cout << "Family: IPV4" << endl;

  // Get and print presentation form of address
  char present[INET_ADDRSTRLEN];
  sockaddr_in *in = reinterpret_cast<sockaddr_in *>(result->ai_addr);
  inet_ntop(AF_INET, &in->sin_addr, present, INET_ADDRSTRLEN);
  cout << "Address: " << present << endl;
}

void printV6Result(struct addrinfo *result) {
  // For user readability
  cout << "Family: IPV6" << endl;

  // Get and print presentation form of address
  char present[INET6_ADDRSTRLEN];
  sockaddr_in6 *in = reinterpret_cast<sockaddr_in6 *>(result->ai_addr);
  inet_ntop(AF_INET6, &in->sin6_addr, present, INET6_ADDRSTRLEN);
  cout << "Address: " << present << endl;
}
