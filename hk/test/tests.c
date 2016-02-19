#include "test.h"

#include <hk/log.h>

int main(int argc, char* argv[]) {
    int result = HK_PASS;

    if (log_test() != HK_PASS) {
	hkerr("log tests failing...!\n");
	result = HK_FAIL;
    } else {
	hkinfo("log test passing!\n\n");
    }
    
    if (bit_test() != HK_PASS) {
	hkerr("bit tests failing...!\n");
	result = HK_FAIL;
    } else {
	hkinfo("bit tests passing!\n\n");
    }
    
    if (ll_test() != HK_PASS) {
	hkerr("ll tests failing...!\n");
    } else {
	hkinfo("ll tests passing!\n\n");
    }
    
    return result;
}
