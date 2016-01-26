#include "rwx.h"

#include <hk/log.h>
#include <hk/bit.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {  
  if (argc < 2) {
    hklog(HK_FATAL, "must provide a permissions number!\n");
    return 1;
  }

  char* num = argv[1];
  unsigned int user = CTOI(num[0]);
  unsigned int group = CTOI(num[1]);
  unsigned int all = CTOI(num[2]);

  permissions p = { user, group, all };
  
  hk_print_bits(p.user);
  hk_print_bits(p.group);
  hk_print_bits(p.all);

  check_permissions(p);

  return 0;
}
