#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int power(int a, int b){
    if(b==0){
        return 1;
    }else{
        return a*power(a,b-1);
    }
}
int main(){
    int a,b,resultado;
    // Recebe do usuário os valores da base e expoente do problema
    printf("base: ");
    scanf("%i",&a);
    printf("expoente: ");
    scanf("%i",&b);
    // Chama a função 'power' para os parâmetros recebidos
    int result = power(a,b);
    printf("resultado: %i",result); // Imprime o valor do resultado retornado pela função
}
