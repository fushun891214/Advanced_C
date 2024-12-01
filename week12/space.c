#include "space.h"

tTypeScore score_buf[N]; //preallocated memory space

void get_score_space(tTypeScore **pp_score)
{
    for(int i = 0;i < N;i++){
        if(score_buf[i].used == 0){
            score_buf[i].used = 1;
            score_buf[i].loc = i;
            *pp_score = &score_buf[i];
            printf("     getScoreSpace(): giving space numbered %d\n\n",i);
            return;
        }
    }
}

void return_score_space (int loc)
{
    for(int i=0;i<N;i++){
        if(score_buf[i].loc == loc){
            score_buf[i].loc = 0;
            score_buf[i].score = 0;
            score_buf[i].used = 0;
        }
    }
    printf("     returnScoreSpace(): return space numbered %d\n", loc);
}
