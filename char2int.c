// Copyright (c) Andrew McDonald 2019. All rights reserved

// char2int.c : Prints out the unsigned decimal or hex
// representation of a given character.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: char2int [x,d] C\n");
    return EXIT_FAILURE;
  }

  if (*(argv[1]) == 'x') {
    printf("Hex representation of '%s' is 0x%x.\n", 
          argv[2], *((uint8_t*)argv[2]));
  } else if (*(argv[1]) == 'd') {
    printf("Unsigned decimal representation of '%s' is %d.\n", 
          argv[2], *((uint8_t*)argv[2]));
  } else {
    printf("Error: Unknown format specifier.\n");
    return  EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
