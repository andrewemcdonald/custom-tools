// Copyright (c) Andrew McDonald 2019. All rights reserved.

// pim.cc: Prints out the decimal values of some common inet macros.

#include <arpa/inet.h>
#include <iostream>

using namespace std;

int main() {
  cout << "AF_INET: " << AF_INET << endl;
  cout << "AF_INET6: " << AF_INET6 << endl;
  cout << "AF_UNSPEC: " << AF_UNSPEC << endl;
  
  return EXIT_SUCCESS;
}