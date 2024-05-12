#include<stdio.h>
#include<stdlib.h>
int main(){
    char inicial[10], final[10];

    FILE *arquivo = fopen("respostas.txt","r+");
    if(arquivo == NULL){
        printf("ERRO");
        printf("\n");
        system("pause");
        return 1;
    }

    rewind(arquivo);
    for(int i=0;i<10;i++){
        fscanf(arquivo,"%c",&inicial[i]);
    }

    inicial[10] = '\0';
    for(int i=0;i<10;i++){
        if(inicial[i] == 'V'){
            final[i] = 'F';
        }else if (inicial[i] == 'F'){
            final[i] = 'V';
        }
    }
    final[10] = '\0';
    printf("Vetor de teste: %s\n",inicial);
    printf("Vetor final: %s\n",final);

    fclose(arquivo);
    return 0;
}