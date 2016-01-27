#include "xor.h"

#include <hk/log.h>
#include <hk/bit.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        hklog(HK_ERR, "%s\n", "Must provide two numbers!");
        return 1;
    } else {
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        int num3;
        
        hklog(HK_INFO, "xor_stateless(%d, %d): %d\n", num1, num2, 
               xor_stateless(num1, num2));

        xor_stateful(&num3, num1, num2);
        hklog(HK_INFO, "xor_stateful(%d, %d): %d\n", num1, num2, num3);

#ifdef DEBUG
        hk_print_bits(HK_DEBUG, num1);
        hk_print_bits(HK_DEBUG, num2);
        hk_print_bits(HK_DEBUG, num3);
#endif

        return 0;
    }
}
