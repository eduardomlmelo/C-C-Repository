// Questão 9 da lista de ponteiros PA está incompleta

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char num[50],aux[50];
    printf("Digite o numero desejado: ");
    fgets(num, sizeof(num), stdin);
    int tam = strlen(num);
    for(int i=0;i<tam;i++){
        if(num[i]!='\n' || num[i]!= '\0'){
            aux[i] = num[tam-1-i];
        }
    }
    printf("Numero invertido: %s\n\n",aux);
}