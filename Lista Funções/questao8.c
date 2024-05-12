#include <stdio.h>
#include <stdlib.h>
int fatorial(int n){
    if (n == 0){
        return 1;
    }
    return n*fatorial(n-1);
}
int main(){
    int n,p;
    printf("Digite as variaveis N e P: ");
    scanf("%i %i",&n,&p);
    
    int res = fatorial(n)/fatorial(p)*fatorial(n-p);
    printf("Numero de combinacoes eh: %i",res);
}