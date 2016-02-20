#include "prime.h"

#include <hk/core.h>
#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[]) {
    unsigned long long int i;
    for (i=0; i <= ULLONG_MAX; i++) {
	if (is_prime(i)) {
	    printf("%llu\n", i);
	}
    }
    
    return HK_OK;
}
