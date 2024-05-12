#include<stdio.h>
#include<stdlib.h>
int lineCounter(FILE *arquivo){
    int contador=0;
    char caractere;
    while((caractere = fgetc(arquivo)) != EOF){
        contador++;
    }
    return contador;
}

int main(){
    FILE *arquivo = fopen("arquivo.txt","r");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }
    int qntLinhas = lineCounter(arquivo);
    printf("O arquivo tem %i linhas",qntLinhas);
    fclose(arquivo);
}