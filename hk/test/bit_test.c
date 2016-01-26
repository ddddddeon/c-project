#include <stdio.h>
#include <hk/hk.h>

int bit_test(int argc, char* argv[]) {
  hklog(HK_INFO, "%d\n", HK_BIT_4);
  hk_print_bits(HK_BIT_4);
  return 0;
}
