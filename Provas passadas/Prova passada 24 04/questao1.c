#include <stdio.h>
#include <stdlib.h>
int main(){
    // primeira parte referente ao item 1
    int  i, index;
    float tempos[8], vel[8], d;
    printf("Digite o comprimento da pista: ");
    scanf("%f",&d);
    if (d<=0){
        printf("Erro, distancia invalida");
        exit(0);
    }
    // segunda parte referente ao item 2
    for(i=0;i<8;i++){
        printf("Digite o tempo de corrida do corredor[%i]: ",i);
        scanf("%f",&tempos[i]);
        if(tempos[i] <= 0){
            printf("erro, tempo invalido");
            exit(0);
        }
        vel[i] = d/tempos[i];
    }
    for(i+0;i<8;i++){
        if (vel[i]>vel[i+1]){
            int temp = vel[i];
            vel[i] = vel[i+1];
            vel[i+1] = temp;
        }
    }
    printf("o PRIMEIRO lugar e o %i, com vel media %f",8,vel[8]);
    printf("o SEGUNDO lugar e o %i, com vel media %f",7,vel[7]);
    printf("o TERCEIRO lugar e o %i, com vel media %f",6,vel[6]);
}