#include <stdio.h>
#include <stdlib.h>
int main(){
    float tempos[7], vel[7], maior;
    int dist, indice;
    printf("Insira o comprimento da pista: ");
    scanf("%i",&dist);
    if (dist <= 0){
        printf("Erro, distancia invalida");
        exit(0);
    }
    for (int i=0;i<7;i++){
        maior = 0;
        printf("Insira o tempo de prova do corredor[%i] :",i);
        scanf("%f",&tempos[i]);
        vel[i] = dist/tempos[i];
        if(tempos[i]<=0){
            printf("Erro, tempo invalido");
            exit(0);
        }
    }
    printf("Lista da velocidade media dos corredores\n");
    for(int i=0;i<7;i++){
        if(vel[i]>vel[i+1]){
            int temp = vel[i];
            vel[i]=vel[i+1];
            vel[i+1]=temp;
        }
    printf("%f ",vel[i]);
    }
    printf("\n");
    printf("o corredor %i teve a maior vel:%f\n",7,vel[7]);
    printf("o corredor %i teve a 2 maior vel:%f\n",6,vel[6]);
    printf("o corredor %i teve a 3 maior vel:%f\n",5,vel[5]);
}