#include <stdio.h>
int main(){
    int l, c;
    // Parte responsável por fazer o usuário definir as dimensões da matriz
    printf("Digite a quantidade de linhas: ");
    scanf("%i",&l);
    printf("Digite a quantidade de colunas: ");
    scanf("%i",&c);
    int matriz[l][c];
    // Loop resposável por definir os valores dos elementos da matriz
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            if(i<j){
                matriz[i][j] = 2;
            }else{
            if(i>j){
                matriz[i][j] = 1;
            }else{
            if(i==j){
                matriz[i][j] = 0;
                }
            }
            }
        }
    }
    // Loop responsável por imprimir os valores da matriz linha a linha
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
}