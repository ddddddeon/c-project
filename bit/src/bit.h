#ifndef BIT_H
#define BIT_H

#define VAL_1 1U
#define VAL_2 2U
#define VAL_3 4U
#define VAL_4 8U
#define VAL_5 16U
#define VAL_6 32U
#define VAL_7 64U
#define VAL_8 128U
#define VAL_9 256U
#define VAL_10 512U
#define VAL_11 1024U
#define VAL_12 2048U
#define VAL_13 4096U
#define VAL_14 8192U
#define VAL_15 8192U * 2U
#define VAL_16 8192U * 4U
#define VAL_17 8192U * 8U
#define VAL_18 8192U * 16U
#define VAL_19 8192U * 32U
#define VAL_20 8192U * 64U
#define VAL_21 8192U * 128U
#define VAL_22 8192U * 256U
#define VAL_23 8192U * 512U
#define VAL_24 8192U * 1024U
#define VAL_25 8192U * 2048U
#define VAL_26 8192U * 4096U
#define VAL_27 8192U * 8192U 
#define VAL_28 (8192U * 8192U) * 2U
#define VAL_29 (8192U * 8192U) * 4U
#define VAL_30 (8192U * 8192U) * 8U
#define VAL_31 (8192U * 8192U) * 16U
#define VAL_32 (8192U * 8192U) * 32U

#define VAL_EMPTY 0U
#define VAL_FULL (VAL_32 - 1U) | VAL_32

char* int2bin(unsigned int i);
void printSet(unsigned int set);

#endif /* !BIT_H */
