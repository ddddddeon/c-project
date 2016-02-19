#include "tea.h"

#include <stdint.h>
#include <hk/log.h>

void encrypt_chunk(uint32_t* v, uint32_t* k) {
    uint32_t i;
    uint32_t sum=0; 
    uint32_t delta = 0x9e3779b9;
    
    uint32_t v0 = v[0]; 
    uint32_t v1 = v[1];
    
    uint32_t k0=k[0];
    uint32_t k1=k[1];
    uint32_t k2=k[2];
    uint32_t k3=k[3];
    
#ifdef TEA_DEBUG
    hk_debug("start: %u %u (sum %u)\n", v0, v1, sum);
#endif
    
    for (i = 0; i < 32; i++) {
	sum += delta;
	v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
	v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
	
#ifdef TEA_DEBUG
	hk_debug("round %u: %u %u (sum %u)\n", i+1, v0, v1, sum);
#endif
    }
    v[0] = v0;
    v[1] = v1;
}

void decrypt_chunk(uint32_t* v, uint32_t* k) {
    uint32_t sum = 0xc6ef3720;
    uint32_t i;
    uint32_t delta = 0x9e3779b9;
    
    uint32_t v0 = v[0];
    uint32_t v1 = v[1]; 
    
    uint32_t k0 = k[0];
    uint32_t k1 = k[1];
    uint32_t k2 = k[2];
    uint32_t k3 = k[3];
    
#ifdef TEA_DEBUG
    hk_debug("start: %u %u (sum %u)\n", v0, v1, sum);
#endif
    
    for (i=0; i < 32; i++) {
	v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
	v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
	sum -= delta;
	
#ifdef TEA_DEBUG
	hk_debug("round %u: %u %u (sum %u)\n", i+1, v0, v1, sum);
#endif
    }
    v[0] = v0;
    v[1] = v1;
}

void encrypt(uint32_t* v, uint32_t* k) {
    uint32_t i;
    uint32_t v_length = LEN(v);
    uint32_t chunk[2];
    
    for (i = 0; i < v_length; i += 2) {    
	chunk[0] = v[i];
	chunk[1] = v[i+1];
	
#ifdef TEA_DEBUG
	hk_debug("%c %c\n", chunk[0], chunk[1]);
	hk_debug("%d %d\n", chunk[0], chunk[1]);
#endif
	hk_debug("v[i]: %d, chunk[0]: %d\n", sizeof(v[i]), sizeof(chunk[0]));
	encrypt_chunk(chunk, (uint32_t *) k);
	
#ifdef TEA_DEBUG
	hk_debug("%c %c\n", chunk[0], chunk[1]);
	hk_debug("%d %d\n", chunk[0], chunk[1]);
#endif
	
	v[i] = chunk[0];
	v[i+1] = chunk[1];
    }
}

void decrypt(uint32_t* v, uint32_t* k) {
    int i;
    int v_length = sizeof(v) / sizeof(v[0]);
    
    for (i = 0; i < v_length; i += 2) {
	hk_debug("%c %c\n", v[i], v[i+1]);
    }
}
