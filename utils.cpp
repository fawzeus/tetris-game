#include "utils.hpp"
int rand_int(int a, int b){
    if (a==b) return a;
    srand(time(0));
    if(a>=0)return rand()%(b-a)+a;
    else{
        if (b>=0){
            return rand()%(b-a)+a;
        }
        else {
            a*=-1;
            b*=-1;
            return -1*rand()%(a-b)+b;
        }
    }
}