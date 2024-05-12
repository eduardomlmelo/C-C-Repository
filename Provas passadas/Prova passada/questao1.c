#include <stdio.h>
#include <stdlib.h>
int main(){
    int m, n;
    // faz o usuário inserir as dimensões do problema
    printf("Digite quantos numeros vc quer: ");
    scanf("%i",&m);
    if(m<=0){
        printf("Erro, quantidade invalida");
        exit(0);
    }
    printf("Digite o numero n: ");
    scanf("%i",&n);
    if(n<=0){
        printf("Erro, numero invalido");
        exit(0);
    }
    int vetor[m];
    // loop responsavel por escanear os elementos do vetor
    for(int i=0;i<m;i++){
        printf("Insira um numero: ");
        scanf("%i",&vetor[i]);
    }
    // loop responsável por imprimir os elementos do vetor, seguindo a ordem da questão
    for(int i=0;i<n;i++){
        if (i % 2 == 0){
            printf("%i ",vetor[i/2]); // imprime os elementos pares [primeiro, terceiro, quinto,...] do vetor
        }else{
            printf("%i ",vetor[m-1-i/2]); // imprime os elementos impares [segundo, quarto, sexto,...] do vetor
        }
    }
}