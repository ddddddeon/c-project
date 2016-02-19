#include "test.h"

#include <stdio.h>
#include <hk/log.h>

int log_test(int argc, char* argv[]) {
  printf("[*] log tests:\n");
  hkinfo("everything is fine%s\n", "!");
  hkdebug("just debugging%s\n", "...");
  hkwarn("i'm warning you%s\n", "...!");
  hkerr("error%s\n", "!");
  hkfatal("fatal%s\n", "!!");

  hklog_prefix(HK_INFO);
  printf("prefix test\n");

  printf("\n");

  return HK_PASS;
}
