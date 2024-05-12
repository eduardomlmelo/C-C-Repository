#include<stdio.h>
int main(){
    float notas[4], soma=0;
    for(int i=0;i<4;i++){
        printf("Digite a nota %i do aluno: ",i);
        scanf("%f",&notas[i]);
        soma+=notas[i];
    }
    float notaFinal = soma/4;
    printf("Nota Final do aluno: %f",notaFinal);
    return 0;
}