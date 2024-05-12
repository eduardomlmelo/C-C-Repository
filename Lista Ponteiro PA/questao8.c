#include<stdio.h>
#include<stdlib.h>
int main(){
    int vetor[5];
    for(int i=0;i<5;i++){
        printf("Digite o elemento %i do vetor: ",i);
        scanf("%i",&vetor[i]);
    }
    for(int i=0;i<5;i++){
        if(vetor[i]%2 == 0)
            printf("Endereco elemento %i, da posicao %i : %i\n",vetor[i],i,&vetor[i]);
    }
}