#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct
{
    int esquerda;
    int direita;
} pecaDomino;

typedef struct
{
    pecaDomino *maoJogador;
    int tamMao;
} jogador;

typedef struct
{
    pecaDomino *pecas;
    int tam;
} bancoPecas;

jogador jogadores[2];
bancoPecas banco;
bancoPecas campo;

int JogadorAtual;

void gerador()
{
    // Função responsável por gerar todas as peças do jogo
    int indice = 0; // Inicializa variável 'indice' que será¡ usada para percorrer todos os elementos do vetor recebido como parâmetro
    for (int i = 0; i <= 6; i++)
    { // Inicia o laço de fora com i=0, que atribuirá¡ os valores de 0 a 6 aos '.esquerda' das peças
        for (int j = i; j <= 6; j++)
        {                                     // Inicia o laço de dentro com j=i, para, dessa forma, não gerar peças repetidas. Pois, 'j' sempre começará¡ em i
            banco.pecas[indice].esquerda = i; // Atribui ao '.esquerda' do elemento atual o valor do 'i' atual
            banco.pecas[indice].direita = j;  // Similar ao anterior, atribui, agora, o '.direita'
            indice++;                         // Incrementa o 'indice', apÃ³s cada atribuição completa de peça, para preencher todo o vetor
        }
    }
}

void embaralhador()
{
    // Função reponsável por embaralhar todas as peças do jogo
    for (int i = 0; i < 28; i++)
    {                                            // Inicia o laço de fora que percorrerá¡ todo o vetor recebido como parâmetro
        int aleatorio = rand() % 27;             // Atribui à variável 'aleatorio', um índice aleatório do vetor parâmetro
        pecaDomino temp = banco.pecas[i];        // Atribui à temporária, o elemento atual determinado pelo laço
        banco.pecas[i] = banco.pecas[aleatorio]; // Atribui ao elemento atual outro elemento, de í­ndice 'aleatorio'
        banco.pecas[aleatorio] = temp;           // Atribui a esse elemento[aleatorio] o valor contido em 'temp'
    }
}

void imprimirMao(int idJogador)
{
    // Função responsável por imprimir no console as peças do jogador selecionado
    int tamMao = jogadores[idJogador].tamMao;
    printf("Mão do jogador %i\n", idJogador);

    if (idJogador == 0)
    {
        for (int i = 0; i < tamMao; i++)
        {
            printf("%i: [%i|%i] ", i, jogadores[idJogador].maoJogador[i].esquerda, jogadores[idJogador].maoJogador[i].direita);
        }
    }

    if (idJogador == 1)
    {
        for (int i = 0; i < tamMao; i++)
        {
            printf("%i: [%i|%i] ", i, jogadores[idJogador].maoJogador[i].esquerda, jogadores[idJogador].maoJogador[i].direita);
        }
    }
    printf("\n");
}


void imprimirCampo()
{
    for (int i = 0; i < campo.tam; i++)
    {                                                                       // Laço de repetição que itera todos os elemento do vetor campo
        printf("[%i|%i]", campo.pecas[i].esquerda, campo.pecas[i].direita); // Imprime as peÃ§as presentes no campo até então
    }
}


void removerPeca(pecaDomino *vetor, int *tam)
{
    // Função responsável por diminuir a quantidade de peças
    (*tam)--;

    if (*tam == 0)
    {
        free(vetor);
    }
    else if (vetor != NULL)
    {
        realloc(vetor, (*tam) * sizeof(pecaDomino));
    }
}

void diminuirMao(int idPeca, int idJogador)
{
    for (int i = idPeca; i < jogadores[idJogador].tamMao; i++)
    {
        jogadores[idJogador].maoJogador[i] = jogadores[idJogador].maoJogador[i + 1];
    }
    removerPeca(jogadores[idJogador].maoJogador, &jogadores[idJogador].tamMao);
}