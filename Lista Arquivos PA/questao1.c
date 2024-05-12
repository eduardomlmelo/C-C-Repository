#include <stdio.h>
#include <stdlib.h>

int main(){
    int qnt;
    printf("Digite a quantidade de estoques: ");
    scanf("%d",&qnt);
    int filial1[qnt], filial2[qnt], final[qnt];

    FILE *arq1 = fopen("Filial1.txt","r");
    FILE *arq2 = fopen("Filial2.txt","r");
    FILE *arq3 = fopen("Final.txt","w+");

    if(arq1 == NULL || arq2 == NULL || arq3 == NULL){
        printf("Erro na abertura dos arquivos");
        return 1;
    }

    for(int i=0;i<qnt;i++){
        fscanf(arq1,"%d",&filial1[i]);
        fscanf(arq2,"%d",&filial2[i]);
    }
    for(int i=0;i<qnt;i++){
        final[i] = filial1[i] + filial2[i];
        fprintf(arq3,"%d\n",final[i]);
    }

    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
    system("pause");
    system("cls");
    return 0;

}