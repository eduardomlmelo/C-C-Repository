#include <stdio.h>
int main(){
    // faz o usuário definir as dimensões da matriz
    int linha, coluna, k=0;
    printf("Insira a quantidade de linhas da matriz: ");
    scanf("%i",&linha);
    printf("Insira a quantidade de colunas da matriz: ");
    scanf("%i",&coluna);
    int matriz[linha][coluna], tam = linha*coluna, ordenador[tam]; 
    // faz o usuário definir os elementos da matriz
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            printf("Digite o elemento[%i][%i] da matriz: ", i, j);
            scanf("%i",&matriz[i][j]);
            ordenador[k++] = matriz[i][j];
        }
    } 
    // imprime os elementos da matriz
    printf("matriz INICIO\n");
    for (int i = 0;i<linha;i++){
        for (int j = 0;j<coluna;j++){
            printf("%3i ",matriz[i][j]);
        }
        printf("\n");
    }
    // reordena os elementos da matriz que estão guardados no vetor ordenador
    int troca;
    do{
        troca = 0;
        for (k=0;k<tam-1;k++){
            if (ordenador[k]>ordenador[k+1]){
                int temp = ordenador[k];
                ordenador[k] = ordenador[k+1];
                ordenador[k+1] = temp;
                troca = 1;
            }
        }
    }while(troca);
    k = 0;
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            matriz[i][j] = ordenador[k++];
        }
    }
        printf("matriz FINAL\n");
    for (int i = 0;i<linha;i++){
        for (int j = 0;j<coluna;j++){
            printf("%3i ",matriz[i][j]);
        }
        printf("\n");
    }
}