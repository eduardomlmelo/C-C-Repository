#include <stdio.h>
int main(){
    float soma=0;
    int contagem=0;
    int q=0;
    float vetor[10];
    float somaf=0;
    for(int i=0;i<10;i++){
        printf("Digite a nota do aluno: ");
        scanf("%f",&vetor[i]);
        soma+=vetor[i];
        contagem+=1;
        if(vetor[i]>=4){
            q+=1;
            somaf+=vetor[i];
        }
    }
    float media=soma/contagem;
    printf("A media dos alunos e: %f\n",media);
    float mediaf = somaf/q;
    printf("A media funcional e: %f\n",mediaf);
}