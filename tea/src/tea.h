#include <stdint.h>

#ifndef TEA_H
#define TEA_H

#define CTOI(i) ( i - '0' )
#define LEN(x) (sizeof(x) / sizeof(x[0]))

void encrypt_chunk(uint32_t* v, uint32_t* k);
void decrypt_chunk(uint32_t* v, uint32_t* k);
void encrypt(uint32_t* v, uint32_t* k);
void decrypt(uint32_t* v, uint32_t* k);

#endif /* !TEA_H */
