#include "prime.h"

#include <hk/core.h>

int is_prime(unsigned long long int n) {
    unsigned long long int i;
    for (i=2; i < n; i++) {

	if (n % i == 0) {
	    return HK_FALSE;
	} 
    }

    if (i == n) {
	return HK_TRUE;
    }
    return HK_FALSE;
}
