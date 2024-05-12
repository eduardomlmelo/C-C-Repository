#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main() {
    int m,n;
    printf("Digite o total de numeros: ");
    scanf("%d",&m);
    int vetor[m];
    printf("Digite o intervalo desejado: ");
    scanf("%d",&n);

    for(int i=0;i<m;i++){
        printf("Digite o elemento %i do vetor: ",i);
        scanf("%d",&vetor[i]);
    }

    for(int i=0;i<n;i++){
        if(i%2 == 0){
            printf("%d ",vetor[m-i/2]);
        }else{
            printf("%d ",vetor[m-1-i/2]);
        }
    }

}

