#include<stdio.h>
int main(){
    int n;
    printf("Digite as dimensoes da matriz: ");
    scanf("%i",&n);
    
    int matriz[n][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                matriz[i][j] = 0;
            }else{
                if(i>j){
                    matriz[i][j] = 1;
                }else{
                    if(i<j){
                        matriz[i][j] = 2;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%i ",matriz[i][j]);
        }
        printf("\n");
    }
}