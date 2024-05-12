#include <stdio.h>
#include <stdlib.h>
int primeVerif(int num){
    if(num<=1){
        printf("Erro, intervalo ou numero invalidos");
        exit(0);
    }
    for(int i = 2;i*i<=num;i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
void primeCounter(int range){
    int counter = 0, primeSum = 0;
    for(int i=2;i<=range;i++){
        if(primeVerif(i)){
            printf("%i ",i);
            primeSum+=i;
        }
    }
    printf("\n");
}
int main(){
    int range;
    printf("Insira ate qnts numeros vc quer verificar: ");
    scanf("%i",&range);
    primeCounter(range);
}