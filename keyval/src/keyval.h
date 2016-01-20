#ifndef KEYVAL_H
#define KEYVAL_H

typedef struct {
    char* key;
    char* val;
} keyval_t;

int set_keyval(keyval_t* obj, char* key, char* val);
int destroy_keyval(keyval_t* obj);

#endif
