#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char nome[50];
    float preco;
} Comida;

void troca(Comida *a, Comida *b){
    Comida temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    Comida cardapio[3];

    for(int i=0;i<3;i++){
        printf("Digite o NOME da comida %i: ",i);
        fgets(cardapio[i].nome,50,stdin);
    }
    for(int i=0;i<3;i++){
        printf("Digite o PRECO da comida %i: ",i);
        scanf("%f",&cardapio[i].preco);
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<3-1-i;j++){
        if(cardapio[j].preco < cardapio[j+1].preco)
            troca(&cardapio[j],&cardapio[j+1]);
        }
    }
    for(int i=0;i<3;i++){
        printf("NOME: %s PRECO: %f\n",cardapio[i].nome,cardapio[i].preco);
    }
    system("pause");
    system("cls");
    return 0;
}