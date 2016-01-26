#ifndef HK_BIT_H
#define HK_BIT_H

#define HK_BIT_1 1U
#define HK_BIT_2 2U
#define HK_BIT_3 4U
#define HK_BIT_4 8U
#define HK_BIT_5 16U
#define HK_BIT_6 32U
#define HK_BIT_7 64U
#define HK_BIT_8 128U
#define HK_BIT_9 256U
#define HK_BIT_10 512U
#define HK_BIT_11 1024U
#define HK_BIT_12 2048U
#define HK_BIT_13 4096U
#define HK_BIT_14 8192U
#define HK_BIT_15 8192U * 2U
#define HK_BIT_16 8192U * 4U
#define HK_BIT_17 8192U * 8U
#define HK_BIT_18 8192U * 16U
#define HK_BIT_19 8192U * 32U
#define HK_BIT_20 8192U * 64U
#define HK_BIT_21 8192U * 128U
#define HK_BIT_22 8192U * 256U
#define HK_BIT_23 8192U * 512U
#define HK_BIT_24 8192U * 1024U
#define HK_BIT_25 8192U * 2048U
#define HK_BIT_26 8192U * 4096U
#define HK_BIT_27 8192U * 8192U 
#define HK_BIT_28 (8192U * 8192U) * 2U
#define HK_BIT_29 (8192U * 8192U) * 4U
#define HK_BIT_30 (8192U * 8192U) * 8U
#define HK_BIT_31 (8192U * 8192U) * 16U
#define HK_BIT_32 (8192U * 8192U) * 32U

#define HK_BIT_EMPTY 0U
#define HK_BIT_FULL (HK_BIT_32 - 1U) | HK_BIT_32

char* hk_int2bin(unsigned int i);
void hk_print_bits(unsigned int set);
int hk_bit_is_set(unsigned set, unsigned int bit_num);

#endif /* !HK_BIT_H */
