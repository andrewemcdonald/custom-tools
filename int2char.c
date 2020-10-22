// Copyright Andrew McDonald 2019. All rights reserved

// int2char.c : Prints out the character that corresponds to
// the given decimal integer.
// Can also optionally print out a list of all ascii supported characters
// represented by decimal integers 0-255, one per line.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Prints the character interpretation of the given integer.
void printConversion(int n);

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: ./int2char [NUM, \"all\"]\n");
    return EXIT_FAILURE;
  }

  if (strncmp(argv[1], "all", 3) == 0) {
    // Print all int2char conversions, one per line.
    for (int i = 0; i < 256; i++) {
      printConversion(i);
    }
  } else {
    // Print single conversion.
    int n = atoi(argv[1]);

    if (n > 255 || n < 0) {
      printf("Error, number must be integer between 0 and 255.\n");
      return EXIT_FAILURE;
    }

    printConversion(n);
  }

  return EXIT_SUCCESS;
}

void printConversion(int n) {
  printf("%d is represented in ascii as: '%c'.\n", n, n);
}