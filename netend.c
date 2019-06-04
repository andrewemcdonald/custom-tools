// Copyright (c) Andrew McDonald. All rights reserved.

// revend.c : Prints the host-endian interpretation of a given network-endian 
// value (hex or decimal).

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s [NUM]\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Read in integer.
  uint32_t n = strtol(argv[1], NULL, 0);
  if (errno) {
    // strtol failed
    perror("Error");
    return EXIT_FAILURE;
  }

  // Do the conversion.
  n = ntohl(n);

  // Print results
  printf("%d\n", n);
  
  return EXIT_SUCCESS;
}