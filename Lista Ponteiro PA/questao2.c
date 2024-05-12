#include<stdio.h>
#include<math.h>
int power(int a, int b){
    int resultado pow(a,b);
    return resultado;
}
int main(){
    int a,b;
    printf("Digite dois numeros: ");
    scanf("%d %d ",&a,&b);

    int resultado = power(a,b); // Passagem de parâmetros por referência

    int resultado2 = pow(2,3); // Passagem de parâmetros por valor
}