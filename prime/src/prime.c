#include "prime.h"

#include <hk/core.h>
#include <stdio.h>
#include <limits.h>

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

void find_primes(unsigned long long int start, unsigned long long int end) {
    unsigned long long int i;

    if (start % 2 == 0) {
	start++;
    }

    for (i=start; i <= end; i+=2) {
	if (is_prime(i)) {
	    printf("%llu\n", i);
	}
    }

}
