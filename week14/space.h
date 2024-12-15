#ifndef __SPACE__
#define __SPACE__

#include "main.h"

#define TOTAL_SPACE       23
#define ELEMENT_SIZE      32

extern unsigned long long byte_buf_mask;  
extern int remaining_space; // 存放剩餘空間的變數

// 基本函數保持不變
void init_space(void);
void print_buffer_status(void);

// 涉及 mask 操作的函數
void our_malloc(int size, void **target, int *mem_location);  
void our_free(int size, int mem_location);                    
int test_continuous_space(unsigned long long mask, int mask_length, int n);
void set_continuous_bits(unsigned long long *mask, int location, int n);
void clear_continuous_bits(unsigned long long *mask, int location, int n);

#endif