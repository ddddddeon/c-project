#include <stdio.h>
#include <hk/log.h>
#include <hk/bit.h>

#define PASS 0
#define FAIL 1

int bit_test(int argc, char* argv[]) {
  unsigned int result = PASS;

  unsigned int num1 = 7U;
  unsigned int num2 = 1U;

  printf("[*] bit tests:\n");

  hklog(HK_INFO, "integer 7\n");
  hk_print_bits(HK_DEBUG, num1);
  if (hk_bit_is_set(num1, HK_BIT_2)) {
    hklog(HK_INFO, "2nd bit is set in integer %d!\n", num1);
  } else {
    hklog(HK_ERR, "2nd bit is not set in integer %d but should be...\n", num1);
    result = FAIL;
  }

  printf("\n");

  hklog(HK_INFO, "integer 1\n");
  hk_print_bits(HK_DEBUG, num2);
  if (!hk_bit_is_set(num2, HK_BIT_2)) {
    hklog(HK_INFO, "2nd bit is not set in integer %d!\n", num2);
  } else {
    hklog(HK_ERR, "2nd bit is set in integer %d but should be...\n", num2);
    result = FAIL;
  }

  printf("\n");

  hklog(HK_INFO, "integer 7\n");
  hk_print_bits(HK_DEBUG, num1);
  hk_unset_bit(&num1, HK_BIT_2);
  if (!hk_bit_is_set(num1, HK_BIT_2)) {
    hklog(HK_INFO, "2nd bit was unset!\n");
    hklog(HK_INFO, "%d\n", num1);
    hk_print_bits(HK_DEBUG, num1);
    if (num1 != 5) {
      hklog(HK_ERR, "%d is not 5!\n");
      result = FAIL;
    }
  } else {
    hklog(HK_ERR, "2nd bit was not unset...\n");
    result = FAIL;
  }

  printf("\n");
  hklog(HK_INFO, "integer 1\n");
  hk_print_bits(HK_DEBUG, num2);
  hk_set_bit(&num2, HK_BIT_2);
  if (hk_bit_is_set(num2, HK_BIT_2)) {
    hklog(HK_INFO, "2nd bit was set!\n");
    hklog(HK_INFO,"%d\n", num2);
    hk_print_bits(HK_DEBUG, num2);
    if (num2 != 3) {
      hklog(HK_ERR, "%d is not 5!\n");
      result = FAIL;
    }
  } else {
    hklog(HK_ERR, "2nd bit was not set...\n");
    result = FAIL;
  }

  printf("\n");

  return result;
}
