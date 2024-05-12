#include <stdio.h>
int main() {
int y, *p, x;
y = 0; // y recebe 0
p = &y; // p recebe o endereco de y
x = *p; // x recebe o conteudo apontado por p
x = 4; // x recebe 4, ou seja, 4 substitui *p
(*p)++; // Conteudo apontado por p soma +1, ou seja, 0+1=1
x--; // X diminui -1, ou seja, 4-1=3
(*p) += x; // Conteudo apontado por p soma com x, ou seja, 1+3=4
printf("y = %d\n", y); // Imprime y
return 0; // retorna 0 para o fim da função
}