#include "bit.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
  unsigned set = VAL_FULL;

  printSet(set);

  set = ~VAL_2;
  printf("%s <--- (~2)\n", int2bin(set));
  
  set &= ~VAL_3;
  printf("%s <--- (set|~4)\n", int2bin(set));

  set &= ~VAL_5;
  printf("%s <--- (set|~16)\n", int2bin(set));

  set |= VAL_3;
  printf("%s <--- (set|4)\n", int2bin(set));  

  set >>= VAL_1;
  printf("%s <--- (set>>1)\n", int2bin(set));

  set <<= VAL_1;
  printf("%s <--- (set<<1) bit-rot!!\n", int2bin(set));

  set |= VAL_1;
  printf("%s <--- (set|1) fixed it\n", int2bin(set));

  set &= VAL_1;
  printSet(set);

  set = VAL_1 + VAL_3;
  printSet(set);

  set+= VAL_5;
  printSet(set);

  while (set <= ((VAL_27 * set) + (VAL_25 + VAL_1))) {
    set = (set * VAL_3) + VAL_1;
    printSet(set);
  } 

  set = ~set;
  printSet(set);

  return 0;
}
