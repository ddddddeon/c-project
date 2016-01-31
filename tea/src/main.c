#include "tea.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <hk/log.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    return 1;
  }

  uint32_t v[2];
  uint32_t k[4];

  v[0] = CTOI(argv[1][0]);
  v[1] = CTOI(argv[1][1]);

  k[0] = CTOI(argv[2][0]);
  k[1] = CTOI(argv[2][1]);
  k[2] = CTOI(argv[2][2]);
  k[3] = CTOI(argv[2][3]);

  encrypt(v, k);
  hklog(HK_INFO, "%u %u\n", v[0], v[1]);
  decrypt(v, k);
  hklog(HK_INFO, "%u%u\n", v[0], v[1]);

  return 0;
}
