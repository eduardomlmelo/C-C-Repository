#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    int tam1, tam2;
    char str1[100], str2[100];
    printf("1\n");
    fgets(str1,100,stdin);
    printf("2\n");
    fgets(str2,100,stdin);
    tam1 = strlen(str1);
    tam2 = strlen(str2);
    int tam3 = tam1+tam2-2;
    char str3[tam3];
    for(int i=0;i<tam1-1;i++){
        str3[i] = str1[i];
    }
    for(int i=0;i<tam2-1;i++){
        str3[tam1-1+i] = str2[i];
    }
    printf("String concatrenada: \n");
    printf("%s",str3);
}