#include <stdio.h>
#include <stdlib.h>
typedef struct endereco{
        int numero;
        
        int cep[8];
    }rua;
int troca(rua *a, rua*b){
    rua temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int tam;
    printf("Digite quantas coms vc quer: ");
    scanf("%i",&tam);
    rua ruas[tam];
    for(int i=0;i<tam;i++){
        printf("Digite o numero da rua %i: ",i);
        scanf("%i",&ruas[i].numero);
    }
    for(int i=0;i<tam;i++){
        printf("Digite o cep da rua: %i",i);
        scanf("%i",&ruas[i].cep);
    }
    //int i=0;i<tam;i++){
    //printf("Digite o nome da rua: %i",i);
    //gets(ruas[i].nome);
    //
    for(int i=0;i<tam-1;i++){
        for(int j=0;j<tam-j-1;j++){
            if(ruas[j].numero>ruas[j+1].numero)
                troca(&ruas[j],&ruas[j+1]);
        }
    }
    printf("\n");
    for(int i=0;i<tam;i++){
        printf("numero da rua %i: %i",i,ruas[i].numero);
    }
}