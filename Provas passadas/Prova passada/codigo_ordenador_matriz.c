#include <stdio.h>
int main(){
    // parte do código responsável por fazer o usuário inserir as dimensões da matriz
    int l,c,i,j,k = 0,troca=0;
    printf("Insira a quantidade de linhas: ");
    scanf("%i",&l);
    printf("Insira a quatidade de colunas: ");
    scanf("%i",&c);
    int matriz[l][c], vetor[l*c];
    // loop responsável por fazer o usuário inserir os elementos da matriz
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("Insira o elemento [%i][%i]: ",i,j);
            scanf("%3i",&matriz[i][j]);
            vetor[k++] = matriz[i][j];
        }
    }
    // loop responsável por imprimir todos os elementos da matriz, alinhados na forma padrão
    printf("matriz DESORDENADA\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
    printf("Digite 1 para ordenar em ordem CRESCENTE\n");
    printf("Digite 2 para ordenar em ordem DECRESCENTE\n");
    int op;
    scanf("%i",&op);
    if(op == 2){
    // loop responsável por ordenar os elementos da matriz, armazenados no vetor ordenador, em ordem decrescente
    do
    {
    troca=0;
    for(i=0;i<l*c-1;i++){
        if(vetor[i]<vetor[i+1]){
            int temp = vetor[i];
            vetor[i]=vetor[i+1];
            vetor[i+1]=temp;
            troca = 1;
        }
    }
    } while (troca!=0);
    for(i=0;i<l;i++){
        for (j=0;j<c;j++)
        {
            matriz[i][j] = vetor[k++];
        }
        
    }
                // loop responsável por imprimir os elementos da matriz, agora, reordenados
    printf("matriz ORDENADA\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            matriz[i][j] = vetor[k++];
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
        }
    }else{
    if(op == 1){
    // loop responsável por ordenar os elementos da matriz, armazenados no vetor ordenador, em ordem crescente
    do
    {
    troca=0;
    for(i=0;i<l*c-1;i++){
        if(vetor[i]>vetor[i+1]){
            int temp = vetor[i];
            vetor[i]=vetor[i+1];
            vetor[i+1]=temp;
            troca = 1;
        }
    }
    } while (troca!=0);
    for(i=0;i<l;i++){
        for (j=0;j<c;j++)
        {
            matriz[i][j] = vetor[k++];
        }
        
    }
                // loop responsável por imprimir os elementos da matriz, agora, reordenados
    printf("matriz ORDENADA\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
        }
    }
    }
}