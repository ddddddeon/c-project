#include "keyval.h"

#include <hk/log.h>

int main(int argc, char* argv[]) {
    keyval_t kv;

    if (argc < 3) {
        hkerr("Usage: keyval key val\n");
        return 1;
    }
    
    char* key = argv[1];
    char* val = argv[2];

    set_keyval(&kv, key, val);
    hkinfo("%s: %s\n", kv.key, kv.val);

    destroy_keyval(&kv);

    return 0;
}
