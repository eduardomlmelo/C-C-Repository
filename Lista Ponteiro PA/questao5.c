#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p1, *p2, x=1,y=2;
    p1 = &x;
    p2 = &y;
    if(p1>p2){
        printf("%i > %i",p1,p2);
    }else{
        printf("%i < %i",p1,p2);
    }
}