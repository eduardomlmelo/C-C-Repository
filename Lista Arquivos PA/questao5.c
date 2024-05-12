#include<stdio.h>
#include<stdlib.h>
int tam=1;
char *string, caractere;
int main(){
    FILE *arquivo = fopen("arq.txt","w+");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo");
        return 1;
    }
    string = (char*)malloc(tam*sizeof(char));
    printf("Insira um caractere do arquivo: ");
    scanf("%s",&string[0]);
    while(1){
        tam++;
        string = (char*)realloc(string, tam*sizeof(char));
        scanf("%s",&string[tam-1]);
        if(string[tam-1] == '#')
            break;
    }
    rewind(arquivo);
    for(int i=0;i<tam;i++){
        if(string[i]!='#')
            fputc(string[i],arquivo);
    }

    fclose(arquivo);
    free(string);
}