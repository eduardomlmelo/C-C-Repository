#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    float altura;
}cadastro;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

int main(){
    int n;
    cadastro *fichas;
    printf("Digite a quantidade de fichas desejada: ");
    scanf("%i",&n);
    fichas = (cadastro*)malloc(n*sizeof(cadastro));
    if(fichas == NULL)
        printf("Erro na alocacao de memoria");
    for(int i=0;i<n;i++){
        printf("Digite o nome do aluno %i: ",i);
        limparBuffer();
        gets(fichas[i].nome);
        printf("\nDigite a idade do aluno %i: ",i);
        scanf("%i",&fichas[i].idade);
        printf("\nDigite a altura do aluno %i: ",i);
        scanf("%f",&fichas[i].altura);
    }
    for(int i=0;i<n;i++){
        printf("nome do aluno %i: %s\n",i,fichas[i].nome);
        printf("idade do aluno %i: %i\n",i,fichas[i].idade);
        printf("altura do aluno %i: %f\n",i,fichas[i].altura);
    }
    
    free(fichas);
}