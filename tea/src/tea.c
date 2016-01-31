#include "tea.h"

#include <stdint.h>
#include <hk/log.h>

void encrypt(uint32_t* v, uint32_t* k) {
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
  hklog(HK_DEBUG, "start: %u %u (sum %u)\n", v0, v1, sum);
  #endif

  for (i = 0; i < 32; i++) {
    sum += delta;
    v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
    v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);

    #ifdef TEA_DEBUG
    hklog(HK_DEBUG, "round %u: %u %u (sum %u)\n", i+1, v0, v1, sum);
    #endif
  }
  v[0] = v0;
  v[1] = v1;
}

void decrypt(uint32_t* v, uint32_t* k) {
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
  hklog(HK_DEBUG, "start: %u %u (sum %u)\n", v0, v1, sum);
  #endif

  for (i=0; i < 32; i++) {
    v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
    sum -= delta;

    #ifdef TEA_DEBUG
    hklog(HK_DEBUG, "round %u: %u %u (sum %u)\n", i+1, v0, v1, sum);
    #endif
  }
  v[0] = v0;
  v[1] = v1;
}
