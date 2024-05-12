#include <stdio.h>
int main(){
    int l,c;
    // faz o usuario definir as dimensoes da matriz
    printf("Insira as dimensoes da matriz: ");
    scanf("%i %i",&l,&c);
    int matriz[l][c];
    for(int i=0;i<l;i++){
        for(int j=0;j<c;j++){
           matriz[i][j] = i + j;
        }
    }
    // imprime os elementos da matriz
    for (int i=0;i<l;i++){
        for (int j=0;j<c;j++){
            printf("%i\t",matriz[i][j]);
        }
        printf("\n");
    }
    }
    