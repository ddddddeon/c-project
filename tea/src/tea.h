#include <stdint.h>

#ifndef TEA_H
#define TEA_H

#define CTOI(i) ( i - '0' )

void encrypt(uint32_t* v, uint32_t* k);
void decrypt(uint32_t* v, uint32_t* k);

#endif /* !TEA_H */
