#include <stdio.h>
int main(){
    // faz o usuario escolher o tamanho do vetor
    int q;
    printf("Digite o tamanho do vetor: ");
    scanf("%i",&q);
    int vetor[q];
    // faz o usuario determinar os elementos do vetor
    for(int i =0;i<q;i++){
        printf("Digite o elemento do vetor: ");
        scanf("%i",&vetor[i]);
    }
    // reordenar o vetor em ordem crescente
    for(int i=0;i<q-1;i++){
        if (vetor[i]>vetor[i+1]){
            int temp = vetor[i];
            vetor[i] = vetor[i+1];
            vetor[i+1] = temp;
        }
    }
    // imprime o vetor reordenado
    for(int i =0;i<q;i++){
        printf("%i ",vetor[i]);
    }
}