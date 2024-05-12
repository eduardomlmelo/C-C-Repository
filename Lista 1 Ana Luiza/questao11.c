#include <stdio.h>
int main(){
    int soma0,soma1,soma2,soma3,soma4,contagem = 0;
    int i = 0,j = 0;
    int matriz[5][5] = {
    {1,2,3,4,5},
    {6,7,8,9,10},
    {11,12,13,14,15},
    {16,17,18,19,20},
    {21,22,23,24,25}
    };
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%i\t",matriz[i][j]);
    	soma0 = soma0 + matriz[0][i];
        soma1 = soma1 + matriz[1][i];
        soma2 = soma2 + matriz[2][i];
        soma3 = soma3 + matriz[3][i];
        soma4 = soma4 + matriz[4][i];
    	contagem = contagem + 1;
        }
    }
    printf(" \n");
    float media0 = soma0/contagem;
    float media1 = soma1/contagem;
    float media2 = soma2/contagem;
    float media3 = soma3/contagem;
    float media4 = soma4/contagem;
    printf("%f\n ",media0);
    printf("%f\n ",media1);
    printf("%f\n ",media2);
    printf("%f\n ",media3);
    printf("%f\n ",media4);

}
