#include<stdio.h>
#include<stdlib.h>
int main(){
    int contador=0, fcontador=0;
    FILE *arquivo = fopen("file.txt","r+");
    for(int i=0;;i++){
        int c = fgetc(arquivo);
        if(c == EOF){
            break;
        }
        contador++;
    }
    rewind(arquivo);
    int num, string[contador];
    printf("Digite o inteiro desejado: ");
    scanf("%i",&num);
    for(int i=0;i<contador;i++){
        int c = fgetc(arquivo);
        if(c == EOF){
            break;
        }
        string[i] = c;
    }
    for(int i=0;i<contador;i++){
        if(string[i] == num)
            fcontador++;
    }
    fclose(arquivo);
    printf("O numero %i aparece %d vezes no arquivo",num,fcontador);
}