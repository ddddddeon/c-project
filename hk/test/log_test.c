#include "test.h"

#include <stdio.h>
#include <hk/log.h>

int log_test(int argc, char* argv[]) {
  printf("[*] log tests:\n");
  hklog(HK_INFO, "everything is fine%s\n", "!");
  hklog(HK_DEBUG, "just debugging%s\n", "...");
  hklog(HK_WARN, "i'm warning you%s\n", "...!");
  hklog(HK_ERR, "error%s\n", "!");
  hklog(HK_FATAL, "fatal%s\n", "!!");

  hklog_prefix(HK_INFO);
  printf("prefix test\n");

  printf("\n");

  return HK_PASS;
}
