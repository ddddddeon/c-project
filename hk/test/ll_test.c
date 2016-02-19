#include "test.h"

#include <stdio.h>
#include <hk/log.h>
#include <hk/ll.h>

int ll_test(int argc, char* argv[]) {
    unsigned int result = HK_PASS;

    printf("[*] ll tests:\n");

    /* ll_create */
    ll_t *cur = ll_create(0);    
    
    /* ll_push */
    ll_push(&cur, 420);
    ll_push(&cur, 69);
    ll_push(&cur, 666);
    hkinfo("pushed 3 values: 420, 69, 666\n");
    printf("\n");

    /* ll_find */
    int num = ll_find(cur, 2);
    hkinfo("value at index 2: %d\n", num);
    if (num != 420) {
	result = HK_FAIL;
    }
    printf("\n");

    /* ll_pop */
    int n;
    ll_pop(&cur, &n);
    hkinfo("popped %d off the list and assigned to n\n", n);
    if (n != 666) {
	result = HK_FAIL;
    }
    printf("\n");

    hkinfo("remaining items in list:\n");
    while(cur) {
	hkinfo("%d\n", cur->val);
	cur = cur->next;
    }
    printf("\n");

    return result;
}
