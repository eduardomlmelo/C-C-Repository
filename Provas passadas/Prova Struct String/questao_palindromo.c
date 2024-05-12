#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char str1[6], str2[6];
    printf("Digite a 1 string: ");
    fgets(str1,sizeof(str1),stdin);
    printf("Digite a 2 string: ");
    fgets(str2,sizeof(str2),stdin);

    str1[strcspn(str1,"\n")] = '\0';
    str2[strcspn(str2,"\n")] = '\0';
    
    printf("%s",str1);
    printf("%s\n",str2);
    
    int tam1 = strlen(str1);
    for(int i=0;i<tam1;i++){
        if(str1[i]!=str2[tam1-i-1]){
            printf("Nao sao palindromas");
            return 0;
        }
    }
    printf("As palavras sao palindromas");
}