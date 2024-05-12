#include <stdio.h>
#include <stdlib.h>
int somatorio(int n1, int n2){
    int soma = 0;
    if(n1 > n2){
        for(int i=n2;i<=n1;i++){
            soma+=i;
        }
    }else{
        for(int i=n1;i<=n2;i++){
            soma+=i;
        }
    }
    return soma;
}
int main(){
    int n1, n2;
    printf("Digite os parametros desejados\n");
    scanf("%i",&n1);
    scanf("%i",&n2);
    int somaF = somatorio(n1,n2);
    printf("Soma resutante: %i",somaF);
}