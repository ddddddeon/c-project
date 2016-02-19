#include "keyval.h"

#include <hk/log.h>

int main(int argc, char* argv[]) {
    keyval_t kv;

    if (argc < 3) {
        hk_err("Usage: keyval key val\n");
        return 1;
    }
    
    char* key = argv[1];
    char* val = argv[2];

    set_keyval(&kv, key, val);
    hk_info("%s: %s\n", kv.key, kv.val);

    destroy_keyval(&kv);

    return 0;
}
