#include "xor.h"

int xor_stateless(int a, int b) {
    return a ^ b;
}

void xor_stateful(int *c, int a, int b) {
    *c = a ^ b;
}
