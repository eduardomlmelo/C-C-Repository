#include<stdio.h>
#include<stdlib.h>
int soma(int *p1, int *p2){
    int res = (*p1)+(*p2);
    return res;
}

int main(){
    int a,b,*p1,*p2;
    printf("Digite dois numeros para a operacao: ");
    scanf("%d %d",&a,&b);

    p1 = &a;
    p2 = &b;

    a = soma(p1,p2);
    printf("o numero 'A' e: %d",a);
}