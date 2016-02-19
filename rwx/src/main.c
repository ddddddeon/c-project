#include "rwx.h"

#include <hk/log.h>
#include <hk/bit.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {  
    if (argc < 2) {
	hkfatal("must provide a permissions number!\n");
	return 1;
    }
    
    char* num = argv[1];
    unsigned int user = CTOI(num[0]);
    unsigned int group = CTOI(num[1]);
    unsigned int all = CTOI(num[2]);
    
    permissions p = { user, group, all };
    
#ifdef DEBUG  
    hk_print_bits(HK_DEBUG, p.user);
    hk_print_bits(HK_DEBUG, p.group);
    hk_print_bits(HK_DEBUG, p.all);
#endif
    
    hklog_prefix(HK_INFO);
    check_permissions(p);
    
    return 0;
}
