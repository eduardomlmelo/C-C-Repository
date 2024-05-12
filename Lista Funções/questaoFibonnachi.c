#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int fibonnachi(int num){
    int prox;
    if(num == 1){
        return 0;
    }else if (num == 2)
    {
        return 1;
    }else{
        prox = fibonnachi(num-1) + fibonnachi(num-2);
    }
    return prox;
}


int main(){
    system("cls");
    setlocale(LC_ALL, "Portuguese");
    int n=0, resultado;

    printf("Digite qual termo você quer saber: ");
    scanf("%d",&n);

    if(n>0){
        resultado = fibonnachi(n);
    }else if (n<=0){
        return main;
    }
    printf("Resutado: %d\n",resultado);
    system("pause");
    system("cls");
    return 0;
}