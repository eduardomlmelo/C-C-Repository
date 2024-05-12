#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct comida{
    char nome[10];
    float preco;
}com;
void troca(com*a,com*b){
    com temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    com c[3];
    int i,j;
    for(i=0;i<3;i++){
        printf("Digite o nome da comida %i ",i+1);
        gets(c[i].nome);
    }
    for(i=0;i<3;i++){
        printf("Digite o preco da comida %i ",i+1);
        scanf("%f",&c[i].preco);
    }
    for(i=0;i<3;i++){
        for(j=0;j<3-i-1;j++){
            if(c[j].preco<c[j+1].preco){
                troca(&c[j],&c[j+1]);
            }
        }
    }
    for(i=0;i<3;i++){
        printf("%s ",c[i].nome);
        printf("%f ",c[i].preco);
    }
}