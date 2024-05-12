#include <stdio.h>
int main(){
    int i,j,k=0,l,c,troca;
    printf("Linhas: ");
    scanf("%i",&l);
    printf("Colunas: ");
    scanf("%i",&c);
    int matriz[l][c], vetor[l*c];
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("Digite o elemento [%i][%i]",i,j);
            scanf("%i",&matriz[i][j]);
            vetor[k++]=matriz[i][j];
        }
    }
    printf("ANTES\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
    do
    {
        troca=0;
        for(i=0;i<l*c-1;i++){
            if(vetor[i]<vetor[i+1]){
                int temp = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = temp;
                troca = 1;
            }
        }
    } while (troca!=0);
    k=0;
    printf("DEPOIS\n");
    for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            matriz[i][j] = vetor[k++];
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
}