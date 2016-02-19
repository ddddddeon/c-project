#include "ll.h"

#include <malloc.h>

ll_t *ll_create(int length) {
    ll_t *cur;
    ll_t *head;
    int i;

    head = NULL;

    for (i=0; i<length; i++) {
        ll_push(&head, LL_INITIALIZE);
    }

    cur = head;
    return cur;
}

void ll_push(ll_t **l, int val) {
    ll_t *cur;
    ll_t *head;

    head = *l;

    cur = (ll_t *) malloc(sizeof(ll_t));
    cur->val = val;
    cur->next = head;

    *l = cur;
}

void ll_pop(ll_t **l, int *var) {
    ll_t *cur = *l;
   
    *var = cur->val;
    *l = cur->next;
    free(cur);
}

int ll_find(ll_t *l, int idx) {
    int i;
    
    for (i=0; i<idx; i++) {
        l = l->next;
    } 
    return l->val;
}
