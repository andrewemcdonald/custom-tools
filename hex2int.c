// Copywrite 2019 Andrew McDonald

// hex2int.c : Prints the decimal representation of a hexadecimal number

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: hex2int 0x<number>");
    return EXIT_FAILURE;
  }

  int n = (int)strtol(argv[1], NULL, 0);

  printf("0x%x in decimal is: %d\n", n, n);

  return EXIT_SUCCESS;
}
