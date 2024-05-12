#include <stdio.h>
#include <stdlib.h>
int ordenador(int q, int vetor[q]){
    for (int i = 0; i < q - 1; i++) {
        for (int j = 0; j < q - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}
int main(){
    int tam;
    printf("Digite o tamanho do vetor: ");
    scanf("%i",&tam);
    int vetor[tam];
    for(int i=0;i<tam;i++){
        scanf("%i",&vetor[i]);
    }
    ordenador(tam,vetor);
    for(int i=0;i<tam;i++){
        printf("%i ",vetor[i]);
    }
}