#include<stdio.h>
typedef unsigned int Int32;

int check_range_loop(Int32 input,Int32 high,Int32 low){
    for(int i=low;i<=high;i++){
        if((input >> i)&1){
            return 1;
        }
    }
    return 0;
}

int check_range_no_loop(Int32 input,Int32 high,Int32 low){
    Int32 mask = 1u << (high-low+1);
    mask -= 1;
    mask = mask << low;
    if((input&mask)>0){
        return 1;
    }
    return 0;
}

int main(void){
    Int32 input;
    Int32 high;
    Int32 low;
    Int32 check;

    while (1){
        printf("Please specify the input:");
        scanf("%x",&input);
        printf("\tPlease specify the high:");
        scanf("%d",&high);
        printf("\tPlease specify the low:");
        scanf("%d",&low);
        printf("check_range_loop result:%d\n",check_range_loop(input,high,low));
        printf("check_range_no_loop result:%d\n\n",check_range_no_loop(input,high,low));
        printf("Input 1 to keep trying the next round:");
        scanf("%x",&check);

        if(check != 1){
            break;
        }
    }
}