#include "bit.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * from http://stackoverflow.com/questions/1024389/ \
 * print-an-int-in-binary-representation-using-c
 */
char* int2bin(unsigned int i) {
  size_t bits = sizeof(int) * CHAR_BIT;

  char* str = malloc(bits + 1);
  if(!str) return NULL;
  str[bits] = 0;

  unsigned u = *(unsigned *)&i;
  for(; bits--; u >>= 1)
    str[bits] = u & 1 ? '1' : '0';

  return str;
}

void printSet(unsigned set) {
  printf("%s <--- %u\n", int2bin(set), set);
}
