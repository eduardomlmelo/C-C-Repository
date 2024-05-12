#include<stdio.h>
#include<stdlib.h>

int primeVerif(int num){
    if(num<=0){
        printf("Numero invalido");
        scanf("%d",&num);
        return primeVerif(num);
    }
    for(int i=2;i*i<=num;i++){
        if(num%i == 0)
            return 0;
    }
    return 1;
}

void primeCounter(int range, FILE *arquive){
    int contador=0;
    for(int i=2;i<=range;i++){
        if(primeVerif(i)){
            fprintf(arquive,"%i ",i);
        }else{
            fprintf(arquive,"n%i ",i);
        }
    }
}

int main(){
    int num;
    FILE *arquivo = fopen("primos.txt","w+");
    printf("Digite ate onde vc quer buscar primos: ");
    scanf("%i",&num);
    primeCounter(num,arquivo);
    fclose(arquivo);
}