#include "space.h"

unsigned char buffer[ELEMENT_SIZE*NUM_BYTE_BUF];
unsigned char byte_buf_mask = 0;

void print_buffer_status (void)
{
    int i;
    unsigned char mask = 0x80;
  
    printf ("      byte_buf_mask: ");
    for (i = 0; i< NUM_BYTE_BUF; i++)
    {
        printf ("%d ", (byte_buf_mask & mask) >> (7-i));
        mask = mask >> 1;
    }

    printf ("\n");
}

void our_malloc(int type, void **target, int *mem_location)
{
    int location;
    
    if (byte_buf_mask == FULL){
        *target = NULL;
        return;
    }
    else if (type == TYPE_SMALL)
    {
        location = test_single_location(byte_buf_mask,NUM_BYTE_BUF);
        if(location >= 0){
            set_single_bit(&byte_buf_mask,location);
            *target = (void *)&buffer[location * ELEMENT_SIZE];
            *mem_location = location;
        }
        else{
            *target = NULL;
            return;
        }
    }
    else
    {
        location = test_dual_location(byte_buf_mask,NUM_BYTE_BUF);
        if (location >= 0)
        {
            set_dual_bit(&byte_buf_mask,location);
            *target = (void *)&buffer[location * ELEMENT_SIZE];
            *mem_location = location;
        }
        else
        {
            *target = NULL;
            return;
        }
    }    
}

int test_single_location(unsigned char mask, int mask_length)
{
    unsigned char test_mask = 0x01; // 0000 0001

    // 尋找單一bit可用空間
    for(int i = 0 ; i < mask_length ; i++){
        if(!(mask & test_mask)){
            return i;
        }
        test_mask = test_mask << 1;
    }
    return -1;
}

void set_single_bit(unsigned char *mask, int location)
{
    unsigned char bit = 0x01 << location; // 將 1 移動到對應的位置
    *mask |= bit; //設置該位為 1 
}

int test_dual_location(unsigned char mask, int mask_length)
{
    unsigned char test_mask = 0x03; // 0000 0011

    // 尋找連續兩個bit可用空間
    for(int i = 0 ; i < mask_length - 1 ; i++){
        if(!(mask & test_mask)){
            return i;
        }
        test_mask = test_mask << 1;
    }
    return -1;
}

void set_dual_bit(unsigned char *mask, int location)
{
    unsigned char bits = 0x03 << location; //將 11 移到對應位置
    *mask |= bits;
}

void clear_single_bit(unsigned char *mask, int location)
{
    unsigned char bit = ~(0x01 << location); // 將 0 移動到指定位置，其他位為 1
    *mask &= bit; // AND運算，將指定位置設為 0 
}

void clear_dual_bit(unsigned char *mask, int location)
{
    unsigned char bit = ~(0x03 << location); // 將 00 移動到指定位置，其他位為 1
    *mask &= bit; // AND運算，將連續兩位設為 0 
}

void our_free(int type, int mem_location)
{
    if (type == TYPE_SMALL)
    {
        clear_single_bit(&byte_buf_mask,mem_location);
    }
    else if (type == TYPE_LARGE)
    {
        clear_dual_bit(&byte_buf_mask,mem_location);
    }
}