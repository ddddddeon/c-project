#include "keyval.h"

#include <stdlib.h>
#include <string.h>

int set_keyval(keyval_t* obj, char* key, char* val) {
    obj->key = malloc(strlen(key));
    obj->val = malloc(strlen(val));

    memcpy(obj->key, key, strlen(key));
    memcpy(obj->val, val, strlen(val));

    return 0;
}

int destroy_keyval(keyval_t* obj) {
    free(obj->key);
    free(obj->val);
    
    return 0;
}

