#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char nome[100];
    int nota;
}Aluno;

int main(){
    int indice = 0;
    Aluno maiorNota, turma[4];

    maiorNota.nota = -1;

    FILE *arquivo = fopen("Alunos.txt","r+");
    if(arquivo == NULL){
        printf("erro");
        printf("\n");
        system("pause");
        system("cls");
        return 1;
    }

    for(int i=0;i<4;i++){
        fscanf(arquivo,"NOME: %s NOTA: %d", turma[i].nome, &turma[i].nota);
        if(turma[i].nota > maiorNota.nota){
            maiorNota.nota = turma[i].nota;
            indice = i;
        }
    }

    printf("Aluno com maior nota:\n");
    printf("NOME: %s NOTA: %d", turma[indice].nome, maiorNota.nota);

    fclose(arquivo);
    printf("\n");
    system("pause");
    system("cls");
    return 0;
}