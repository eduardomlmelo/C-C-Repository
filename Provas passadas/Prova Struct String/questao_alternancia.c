#include<stdio.h>
int main(){
    int q,n;
    printf("Digite a quantidade de numeros desejada: ");
    scanf("%i",&q); // Recebe do usuário a quantidade de números a serem recebidos

    int vetor[q];

    printf("Digite o intevalo desejado: ");
    scanf("%i",&n); // Recebe di usuário o intervalo desejado
    
    printf("Insira os numeros desejados: ");
    for(int i=0;i<q;i++){
        scanf("%i",&vetor[i]); // Atribui ao vetor os números desejados da sequência
    }
    for(int i=0;i<n;i++){
        if(i%2==0){ // Analisa se o resto da divisão de 'i'/2 é 0, ou seja, se 'i' é par
            printf("%i ",vetor[i/2]); // Imprime os números do vetor cujos índices são pares
        }else{
            printf("%i ",vetor[q-1-i/2]); // Imprime os números do vetor cujos índices são ímpares
        }
    }
}