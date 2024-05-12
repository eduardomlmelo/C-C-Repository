#include<stdio.h>
#include<stdlib.h>
int divisores(int num){
    if(num == 1){
        return 1;
    }
    for(int i = 1;i<=num;i++){
        if(num % i == 0){
            printf("%i ",i);
        }
    }
    return 0;
}
int main(){
    int num;
    printf("Digite o numero desejado: ");
    scanf("%i",&num);
    divisores(num);
}