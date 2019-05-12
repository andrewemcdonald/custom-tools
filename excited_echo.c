// Copyright Andrew McDonald 2019. All rights reserved.

// excited_echo.c : Program that works like echo, except
// its adds an exclaimation, making it "excited".

#include <stdlib.h>
#include <stdio.h>

int main (int argc, char** argv) {
  if (argc != 2) {
    printf("Usage: excited_echo STRING\n");
    return EXIT_FAILURE;
  }

  printf("%s!\n", argv[1]);

  return EXIT_SUCCESS;
}
