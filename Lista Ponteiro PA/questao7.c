#include<stdio.h>
#include<stdlib.h>
int main(){
    int matE[3][3], *matD;
    matD = (int*)malloc(9*sizeof(int));
    if(matD == NULL)
        printf("Erro na alocacao de memoria");
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            matE[i][j] = i+j;
        }
    }
    for(int i=0;i<9;i++){
        matD[i] = i+1;
        printf("Enderco do elemento %i, matE: %i\n",matE[i],&matE[i]);
        printf("Endereco do elemento %i, matD: %i\n",matD[i],&matD[i]);
    }
    
    free(matD);
}