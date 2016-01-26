#include <stdio.h>
#include <hk/log.h>
#include <hk/bit.h>

int bit_test(int argc, char* argv[]) {
  unsigned int num1 = 7U;
  unsigned int num2 = 1U;

  hk_print_bits(num1);
  if (hk_bit_is_set(num1, HK_BIT_2)) {
    hklog(HK_INFO, "2nd bit is set in integer %d!\n", num1);
  } else {
    hklog(HK_ERR, "2nd bit is not set in integer %d but should be...\n", num1);
  }

  hk_print_bits(num2);
  if (!hk_bit_is_set(num2, HK_BIT_2)) {
    hklog(HK_INFO, "2nd bit is not set in integer %d!\n", num2);
  } else {
    hklog(HK_ERR, "2nd bit is set in integer %d but should be...\n", num2);
  }

  return 0;
}
