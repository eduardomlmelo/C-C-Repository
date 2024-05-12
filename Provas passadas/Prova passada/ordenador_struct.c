#include<stdio.h>
#include<stdlib.h>
typedef struct comida{
        char nome[10];
        float preco;
    }com;
void troca(com *a, com *b){
    com temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    com c[3];
    for(int i=0;i<3;i++){ // Faz o usuário definir o campo 'nome' de cada struct
        printf("Nome da comida %i:",i);
        gets(c[i].nome);
    }
    for(int i=0;i<3;i++){ // Faz o usuário definir o campo 'preco' de cada struct
        printf("Preco da comida %i:",i);
        scanf("%f",&c[i].preco);
    }
    printf("ANTES\n"); // imprime os dados das struct ANTES da ordenação
    for(int i=0;i<3;i++){
        printf("Comida %i: %s\n",i,c[i].nome);
        printf("Preco comida %i: %f\n",i,c[i].preco);
    }
    print("\n");
    for (int i = 0; i < 3 - 1; i++) { // Utiliza a função 'troca' para ordenar os dados das struct
        for (int j = 0; j < 3 - i - 1; j++) {
            if (c[j].preco < c[j + 1].preco) {
                troca(&c[j], &c[j + 1]);
            }
        }
    }
    printf("\n");
    printf("DEPOIS\n"); // imprime os dados das structs DEPOIS da ordenação
    for(int i=0;i<3;i++){
        printf("Comida %i: %s\n",i,c[i].nome);
        printf("Preco comida %i: %f\n",i,c[i].preco);
    }
}