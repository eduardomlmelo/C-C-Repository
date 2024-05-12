#include <stdio.h>
#include <stdlib.h>
int main (){
    int vcoleta[7], vcons[7], i=0;
    for(i=0;i<7;i++){
        printf("DIgite a qnt de coleta do dia[%i]: ",i);
        scanf("%i",&vcoleta[i]);
    }
    for(i=0;i<7;i++){
        printf("Digite a qnt de consumo do dia[%i]: ",i);
        scanf("%i",&vcons[i]);
    }
    int contagem = 0;
    for(i=0;i<7;i++){
        if (vcoleta[i]-vcons[i]>0){
            contagem += vcoleta[i]-vcons[i];
        }
        else{
            if (vcoleta[i]+contagem-vcons[i]<=0){
                printf("A agua vai acabar no dia [%i]",i);
                exit(0);
            }
        }
    }
    printf("A agua vai durar");
}