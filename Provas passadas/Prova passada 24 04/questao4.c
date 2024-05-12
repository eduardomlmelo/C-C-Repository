// CÓDIGO JOGO DA MEMÓRIA //

#include <stdio.h>
#include <stdlib.h>

// Função rodada designada para executar a rodada de um jogador, fazer as perguntas da questão e armazenar
// o valor dos pontos. Esta função retorna a variável 'pontos' ao final da execução

int rodada(int i){
    int num, erro, resp1, resp2, pontos, maior=0, soma=0, contador=0;
    // Condicinal que avalia quem é o jogador e printa a frase correspondente
    if (i==1){
        printf("Jogada do Jogador 1\n");
    }else{
    if(i==2){
        printf("Jogada do jogador 2\n");
        }
    }
    // Repetição que faz o usuário digitar números, até o mesmo inserir 0
    while (1)
    {
        printf("digite um numero: ");
        scanf("%i",&num);
        if(num == 0){   // Condicinal que encerra o LOOP quando o usuário insere o número 0
        printf("Jogada encerrada\n");
        break;
        }
        contador+=1; // Contador que armazena a QUANTIDADE de números ditos
    // Condicional que compara os números inseridos e armazena o MAIOR valor até então
        if (num>maior){
            maior = num; // Variável que armazena o valor do maior número dito, através do condicional
        }
        soma+=num; // Variável que armazena o valor da SOMA dos números ditos até então
    }
    printf("Jogador [%i], qual e a soma dos numeros ditos? ",i); // PRIMEIRA pergunta da questão
    scanf("%i",&resp1);
    printf("E qual o maior numero dito? "); // SEGUNDA pergunta da questão
    scanf("%i",&resp2);
    pontos = contador;
    // Condicional que verifica se, ao menos uma, pergunta foi respondida corretamente
    if (resp1 != soma){
        printf("Resposta 1 incorreta , a soma e: %i\n",soma);
        pontos = 0; // Atribui valor 0 aos pontos do jogador em questão
    }else{
    if(resp2 != maior){
        printf("Resposta 2 incorreta, o maior numero dito foi: %i\n",maior);
        pontos = 0; // Atribui valor 0 aos pontos do jogador em questão
    }
    }
    printf("Pontos do jogador %i: %i\n", i, pontos);
    return pontos; // Retorna o valor da variável pontos para o jogador em questão
}

// Função principal designada para, inicialmente, definir quem começará o jogo e, em seguida,
// armazena os valores dos pontos dos jogadores. Além disso, ela determina o vencedor do jogo.

int main(pontos){
    // Define qual jogador irá começar o jogo, passando para o outro após o FIM da rodada
    int i, pontos1, pontos2;
    printf("Qual o jogador ira jogar agora? ");
    scanf("%i",&i);
    rodada(i);
    // Codicional resposável por iniciar uma função com base de qual jogador será a a RODADA
    if (i==1){
        pontos1 = pontos; // Faz a variável pontos1 receber os pontos do JOGADOR1
        i=2;
        rodada(i); // Inicia a função para o próximo jogador
    }else{
    if(i==2){
        pontos2 = pontos; // Faz a variável pontos2 receber os pontos do JOGADOR2
        i=1;
        rodada(i); // Inicia a função para o próximo jogador
    }
    }
    // Condicional responsável por averiguar a situação dos pontos dos jogadores, verificando se 1>2 ou 2>1
    if(pontos1>pontos2){
        printf("Jogador 1 venceu");
    }else{
        printf("Jogador 2 venceu");
    }
}