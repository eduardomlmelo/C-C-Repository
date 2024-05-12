#include <stdio.h>
#include <stdlib.h>
int vetor[10];
int soma = 0;
int contagem = 0;
int i = 0;

int main() 
{
for (i = 0; i < 10; i++){ //faz o usuario inserir os valores do vetor
    printf("Digite a nota: ");
    scanf("%d",&vetor[i]);
}
for (i=0;i<10;i++){
	printf("%i ",vetor[i]);
	if (vetor[i]<4){
		soma = soma + vetor[i];
		contagem = contagem + 1;
	}
	
}
int media = soma/contagem;
	printf("A media dos reprovados e: ");
	printf("%d ",media);
}
