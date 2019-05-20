// Copyright 2019 Andrew McDonald

// int2hex.c : Prints the hex form of the given integer.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: int2hex <integer>");
    return EXIT_FAILURE;
  }

  int n = atoi(argv[1]);

  printf("%d in hex is: %x\n", n, n);

  return EXIT_SUCCESS;
}