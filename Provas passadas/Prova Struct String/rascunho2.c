#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char str1[100], str2[100];
    printf("Digite a string 1: ");
    fgets(str1, 100, stdin);
    printf("Digite a string 2: ");
    fgets(str2, 100, stdin);
    int tam1 = strlen(str1), tam2 = strlen(str2), tam3 = tam1+tam2-2;
    char str3[tam3];

    for(int i=0;i<tam1-1;i++){
        str3[i] = str1[i];
    }
    for(int i=0;i<tam2-1;i++){
        str3[tam1-1+i] = str2[i];
    }

    printf("String final: %s", str3);

}