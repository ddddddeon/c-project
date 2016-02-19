#ifndef LL_H
#define LLH

#include "core.h"

#define LL_INITIALIZE 0

struct ll {
    int val;
    struct ll *next;
};

typedef struct ll ll_t;

ll_t *ll_create(int length);
void ll_push(ll_t **l, int val);
void ll_pop(ll_t **l, int *var);
int ll_find(ll_t *l, int idx);

#endif /* !LL_H */
