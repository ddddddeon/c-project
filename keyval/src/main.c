#include "keyval.h"

#include <stdio.h>

int main(int argc, char* argv[]) {
    keyval_t kv;

    if (argc < 3) {
        printf("Usage: keyval key val\n");
        return 1;
    }
    
    char* key = argv[1];
    char* val = argv[2];

    set_keyval(&kv, key, val);
    printf("%s: %s\n", kv.key, kv.val);

    destroy_keyval(&kv);

    return 0;
}
