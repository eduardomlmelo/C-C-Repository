#include <stdio.h>
#include <math.h>
int main(){
    int l,c;
    int soma, contagem = 0;
    // define as dimensões da matriz
    printf("Digite as dimensoes da matriz: ");
    scanf("%i",&l);
    printf("Digite as dimensoes da matriz: ");
    scanf("%i",&c);
    int matriz[l][c];
    // define os elementos da matriz
    for (int i = 0;i<l;i++){
        for (int j = 0;j<c;j++){
            printf("Insira a idade da cidade %i %i ",i,j);
            scanf("%i",&matriz[i][j]);
        }
    }
    // imprime todos os elementos da matriz
    for (int i = 0;i<l;i++){
        for (int j = 0;j<c;j++){
            printf("%i\t\n",matriz[i][j]);
        }
    }
    // calcula a media dos elementos de uma linha selecionada
    int li;
    printf("Digite um indice de um elemento: ");
    scanf("%i",&li);
    for (int i=0;i<c;i++){
    	soma = soma + matriz[li][i];
    	contagem = contagem + 1;
	}
	float media = (float)soma/contagem;
	printf("A media das ciadades selecionadas e: %.2f\n ",media);
	return 0;
}