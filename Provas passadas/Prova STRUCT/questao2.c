#include<stdio.h>
#include<stdlib.h>
typedef struct Aluno{
    char nome[10];
    float notas[4], media;
}not;
int main(){
    not name;
    float soma=0;
    printf("Digite o nome do aluno: ");
    gets(name.nome);
    for(int i=0;i<4;i++){
        printf("Digite a nota %i do aluno %s: ",i,name.nome);
        scanf("%f",&name.notas[i]);
        soma+=name.notas[i];
    }
    float mediaF = soma/4;
    name.media = mediaF;
    printf("A nota final do aluno (%s) e: %f",name.nome,name.media);
}