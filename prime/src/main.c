#include "prime.h"

#include <hk/core.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    int num;
    unsigned long long int i, 
	                   start, 
	                   end;
    
    if (argc < 1) {
	num = 0;
    } else {
	num = atoi(argv[1]);
    }
    
    switch(num) {
    case 0:
	start = 0;
	end = ULLONG_MAX;
    case 1:
	start = 0;
	end = (ULLONG_MAX / 4) - 1;
	break;
    case 2:
	start = ULLONG_MAX / 4;
	end = (ULLONG_MAX / 2) - 1;
	break;
    case 3:
	start = ULLONG_MAX / 2;
	end = ( (ULLONG_MAX / 2) + (ULLONG_MAX / 4) ) - 1;
	break;
    case 4:
	start = ULLONG_MAX / 2 + ULLONG_MAX / 4;
	end = ULLONG_MAX;
	break;
    default:
	return HK_NOK;
    }
    
    for (i=start; i <= end; i++) {
	if (is_prime(i)) {
	    printf("%llu\n", i);
	}
    }
    
    return HK_OK;
}
