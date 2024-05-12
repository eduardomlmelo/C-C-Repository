#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char str1[100],str2[100];
    
    printf("Digite a string 1: ");
    fgets(str1,sizeof(str1),stdin);
    int tam1 = strlen(str1);

    printf("Digite a string 2: ");
    fgets(str2,sizeof(str2),stdin);
    int tam2 = strlen(str2);
    
    char strF[tam1+tam2-2];

    for(int i=0;i<tam1;i++){
    if(str1[i]!='\0' && str1[i]!='\n'){
        strF[i] = str1[i];
    }
    }
    for(int i=0;i<tam2;i++){
    if(str2[i]!='\0' && str2[i]!='\n'){
        strF[tam1+i] = str2[i];
    }
    }
    printf("DEPOIS\n");
    printf("%s",strF);
}