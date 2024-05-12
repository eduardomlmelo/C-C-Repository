#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    char string[100];
    printf("Digite a string desejada: ");
    fgets(string, 100, stdin);
    printf("String digitada: %s",string);
    int tam = strlen(string)-1;
    printf("Tamanho da string: %i\n",tam);
    for(int i=0;i<tam;i++){
        if(string[i] != string[tam-1-i]){
            printf("%c %c",string[i],string[tam-1-i]);
            printf("NAO E PALINDROMO");
            return 0;
        }
    }
    printf("A string e um palindromo");
}