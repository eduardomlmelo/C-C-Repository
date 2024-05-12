#include<stdio.h>
#include<stdlib.h>
int main(){
    int vetE[10], *vetD;
    vetD = (int*)malloc(10*sizeof(int));
    if(vetD == NULL)
        printf("Erro de alocacao de memoria");
    for(int i=0;i<10;i++){
        vetE[i] = i+1;
        vetD[i] = 10-i;
    }
    for(int i=0;i<10;i++){
        printf("Enderco do elemento %i, vetE: %i\n",i,&vetE[i]);
        printf("Endereco do elemento %i, vetD: %i\n",i,&vetD[i]);
    }
    free(vetD);
}