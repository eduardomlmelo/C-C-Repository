#include <stdio.h>
#include <stdlib.h>

float pesoIdeal(int gen, float h){
    float peso;
    if (gen == 1){
        peso = 72.7*h - 58;
    }else{
        if(gen == 2)
        peso = 62.1*h - 44.7;
    }
    return peso;
}
int main(){
    float h;
    int gen;
    printf("Insira o seu genero: ");
    scanf("%i",&gen);
    printf("Insira a sua altura: ");
    scanf("%f",&h);
    float pesoI = pesoIdeal(gen,h);
    printf("\n%f",pesoI);
}