#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[50];
    char dica[50];
} Animal;

int main(){
    Animal cavalo;

    cavalo.nome[6] = "Cavalo";
    cavalo.dica[8] = "Relincha";

    FILE *arquivo = fopen("Jogo.txt","w+");
    fwrite(&cavalo,sizeof(Animal),1,arquivo);
    fclose(arquivo);

}