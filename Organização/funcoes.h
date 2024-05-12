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
    // Fun��o respons�vel por gerar todas as pe�as do jogo
    int indice = 0; // Inicializa vari�vel 'indice' que ser� usada para percorrer todos os elementos do vetor recebido como par�metro
    for (int i = 0; i <= 6; i++)
    { // Inicia o la�o de fora com i=0, que atribuir� os valores de 0 a 6 aos '.esquerda' das pe�as
        for (int j = i; j <= 6; j++)
        {                                     // Inicia o la�o de dentro com j=i, para, dessa forma, n�o gerar pe�as repetidas. Pois, 'j' sempre come�ar� em i
            banco.pecas[indice].esquerda = i; // Atribui ao '.esquerda' do elemento atual o valor do 'i' atual
            banco.pecas[indice].direita = j;  // Similar ao anterior, atribui, agora, o '.direita'
            indice++;                         // Incrementa o 'indice', após cada atribui��o completa de pe�a, para preencher todo o vetor
        }
    }
}

void embaralhador()
{
    // Fun��o repons�vel por embaralhar todas as pe�as do jogo
    for (int i = 0; i < 28; i++)
    {                                            // Inicia o la�o de fora que percorrer� todo o vetor recebido como par�metro
        int aleatorio = rand() % 27;             // Atribui � vari�vel 'aleatorio', um �ndice aleat�rio do vetor par�metro
        pecaDomino temp = banco.pecas[i];        // Atribui � tempor�ria, o elemento atual determinado pelo la�o
        banco.pecas[i] = banco.pecas[aleatorio]; // Atribui ao elemento atual outro elemento, de �ndice 'aleatorio'
        banco.pecas[aleatorio] = temp;           // Atribui a esse elemento[aleatorio] o valor contido em 'temp'
    }
}

void imprimirMao(int idJogador)
{
    // Fun��o respons�vel por imprimir no console as pe�as do jogador selecionado
    int tamMao = jogadores[idJogador].tamMao;
    printf("M�o do jogador %i\n", idJogador);

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
    {                                                                       // La�o de repeti��o que itera todos os elemento do vetor campo
        printf("[%i|%i]", campo.pecas[i].esquerda, campo.pecas[i].direita); // Imprime as peças presentes no campo at� ent�o
    }
}


void removerPeca(pecaDomino *vetor, int *tam)
{
    // Fun��o respons�vel por diminuir a quantidade de pe�as
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