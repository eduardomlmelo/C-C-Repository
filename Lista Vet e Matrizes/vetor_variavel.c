#include <stdio.h>
#include <stdlib.h>
int main()
{
    int tam0 = 5, contador = 0;
    int *vetor;

    vetor = (int *)malloc(tam0 * sizeof(int));

    for (int i = 0;; i++)
    {
        vetor = (int *)realloc(vetor, tam0 + 1 * sizeof(int));
        printf("Digite um elemento para o vetor: ");
        scanf("%i", &vetor[i]);
        if (vetor[i] == 0)
            break;
        contador += 1;
    }

    int tamf = contador + 1 / 4;
    vetor[tamf] = 0;
    for (int i = 0; i < tamf; i++)
    {
        printf("%i ", vetor[i]);
    }
    free(vetor);
}