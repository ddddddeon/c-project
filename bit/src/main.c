#include "bit.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
  unsigned set = VAL_FULL;

  printf("%s\n", int2bin(set));

  set = ~VAL_2;
  printf("%s\n", int2bin(set));
  
  set = ~VAL_3;
  printf("%s\n", int2bin(set));

  set >>= VAL_1;
  printf("%s\n", int2bin(set));

  set <<= VAL_1;
  printf("%s <--- bit-rot\n", int2bin(set));

  set |= VAL_1;
  printf("%s <--- fixed it\n", int2bin(set));

  set = VAL_1 + VAL_3 + VAL_5;
  printSet(set);

  while (set <= ((VAL_27 * set) + (VAL_25 + VAL_1))) {
    set = (set * VAL_3) + VAL_1;
    printSet(set);

  } 

  set = ~set;
  printSet(set);
  return 0;
}
