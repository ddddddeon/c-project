#include <hk/log.h>

#include "test.h"

int main(int argc, char* argv[]) {
  int result = PASS;

  if (log_test() != PASS) {
    hklog(HK_ERR, "log tests failing...!\n");
    result = FAIL;
  } else {
    hklog(HK_INFO, "log test passing!\n\n");
  }

  if (bit_test() != PASS) {
    hklog(HK_ERR, "bit tests failing...!\n");
    result = FAIL;
  } else {
    hklog(HK_INFO, "bit tests passing!\n\n");
  }

  return result;
}
