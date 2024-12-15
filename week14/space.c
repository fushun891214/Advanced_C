#include "space.h"

unsigned char buffer[ELEMENT_SIZE * TOTAL_SPACE];  // 用來儲存實際資料的陣列
unsigned long long byte_buf_mask;  
int remaining_space;

void init_space() {
    byte_buf_mask = 0ULL;  // 初始化為 0
    remaining_space = TOTAL_SPACE;
}

void print_buffer_status(void) {
    printf("      buffer_mask: ");
    
    // 從最高位到最低位印出 TOTAL_SPACE 個位元
    for(int i = TOTAL_SPACE - 1; i >= 0; i--) {
        printf("%d ", (byte_buf_mask & (1ULL << i)) ? 1 : 0);
        // 每 8 位元加一個逗號，除了最後一組
        if(i % 8 == 0 && i != 0) {
            printf(", ");
        }
    }
    printf("\n");
}

void our_malloc(int size, void **target, int *mem_location) {
    if(size <= 0 || size > remaining_space) {
        *target = NULL;
        return;
    }
    
    int location = test_continuous_space(byte_buf_mask, TOTAL_SPACE, size);
    
    if(location >= 0) {
        set_continuous_bits(&byte_buf_mask, location, size);
        remaining_space -= size;
        *target = (void *)&buffer[location * ELEMENT_SIZE];
        *mem_location = location;
    } else {
        *target = NULL;
    }
}

// 測試是否有連續 n 個可用空間
// 返回找到的起始位置，如果找不到則返回 -1
int test_continuous_space(unsigned long long mask, int mask_length, int n) {
    for(int start = 0; start <= mask_length - n; start++) {
        int found = 1;
        
        // 檢查從 start 開始的 n 個位元
        for(int i = 0; i < n; i++) {
            if(mask & (1ULL << (start + i))) {
                found = 0;
                break;
            }
        }
        
        if(found) return start;
    }
    return -1;
}

void our_free(int size, int mem_location) {
    clear_continuous_bits(&byte_buf_mask, mem_location, size);
    remaining_space += size;
}

void set_continuous_bits(unsigned long long *mask, int start_pos, int n) {
    // 設置從 start_pos 開始的 n 個位元為 1
    for(int i = 0; i < n; i++) {
        *mask |= (1ULL << (start_pos + i));
    }
}

void clear_continuous_bits(unsigned long long *mask, int start_pos, int n) {
    // 清除從 start_pos 開始的 n 個位元
    for(int i = 0; i < n; i++) {
        *mask &= ~(1ULL << (start_pos + i));
    }
}