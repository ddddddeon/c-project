#include "test.h"

#include <hk/log.h>

int main(int argc, char* argv[]) {
  int result = HK_PASS;

  if (log_test() != HK_PASS) {
    hklog(HK_ERR, "log tests failing...!\n");
    result = HK_FAIL;
  } else {
    hklog(HK_INFO, "log test passing!\n\n");
  }

  if (bit_test() != HK_PASS) {
    hklog(HK_ERR, "bit tests failing...!\n");
    result = HK_FAIL;
  } else {
    hklog(HK_INFO, "bit tests passing!\n\n");
  }

  if (ll_test() != HK_PASS) {
      hklog(HK_ERR, "ll tests failing...!\n");
  } else {
      hklog(HK_INFO, "ll tests passing!\n\n");
  }

  return result;
}
