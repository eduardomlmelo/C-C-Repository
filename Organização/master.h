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

int podeJogar(int idPeca, int idJogador, int qualLado)
{
    if(qualLado != 0 && qualLado != 1){
        printf("Lado inválido, Digite uma opção disponível\n");
        system("pause");
        return 0;
    }
    if (qualLado == 0)
    { // Jogar peça na ESQUERDA do campo
        campo.tam++;
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
        if (campo.pecas[0].esquerda == jogadores[idJogador].maoJogador[idPeca].direita)
        { // Peça do jogador encaixa normalmente no campo
            for (int i = campo.tam - 2; i >= 0; i--)
            {
                campo.pecas[i + 1].esquerda = campo.pecas[i].esquerda;
                campo.pecas[i + 1].direita = campo.pecas[i].direita;
            } // Loop para copiar todas as peças do campo para uma posição a frente
            campo.pecas[0] = jogadores[idJogador].maoJogador[idPeca];
            // Após isso, a peça jogada foi copiada para a posição 0 do campo
            // CHAMAR A FUNÇÃO DE REMOVER A PEÇA DA MÃO
            diminuirMao(idPeca, idJogador);
            // Copia a peça jogada para a posição vazia mais à direita do campo, determinada pelo loop anterior
        }
        else
        {
            if (campo.pecas[0].esquerda == jogadores[idJogador].maoJogador[idPeca].esquerda)
            { // Peça do jogador deve ser invertida para encaixar
                for (int i = campo.tam - 2; i >= 0; i--)
                {
                    campo.pecas[i + 1].esquerda = campo.pecas[i].esquerda;
                    campo.pecas[i + 1].direita = campo.pecas[i].direita;
                } // Loop para copiar todas as peças do campo para uma posição a frente
                campo.pecas[0].esquerda = jogadores[idJogador].maoJogador[idPeca].direita;
                campo.pecas[0].direita = jogadores[idJogador].maoJogador[idPeca].esquerda; // Inverte a peça jogada e copia na posição 0 do campo
                // Após isso, a peça jogada foi copiada para a posição 0 do campo
                // CHAMAR A FUNÇÃO DE REMOVER A PEÇA DA MÃO
                diminuirMao(idPeca, idJogador);
                // Copia a peça jogada para a posição vazia mais à direita do campo, determinada pelo loop anterior
            }
            else
            {
                campo.tam--;
                campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
                printf("Jogada inválida, escolha uma peça correta\n");
                system("pause");
                return 0;
            }
        }
    }
    else
    {
        if (qualLado == 1)
        { // Jogar peça na DIREITA do campo
            campo.tam++;
            campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
            if (campo.pecas[campo.tam - 2].direita == jogadores[idJogador].maoJogador[idPeca].esquerda)
            { // Peça encaixa normalmente no campo
                campo.pecas[campo.tam - 1] = jogadores[idJogador].maoJogador[idPeca];
                // Após isso, a peça jogada foi copiada para a posição 0 do campo
                // CHAMAR A FUNÇÃO DE REMOVER A PEÇA DA MÃO
                diminuirMao(idPeca, idJogador);
                // Copia a peça jogada para a posição vazia mais à direita do campo, determinada pelo loop anterior
            }
            else
            {
                if (campo.pecas[campo.tam - 2].direita == jogadores[idJogador].maoJogador[idPeca].direita)
                { // Peça deve ser invertida para encaixar no campo
                    int aux;
                    aux = jogadores[idJogador].maoJogador[idPeca].esquerda;
                    jogadores[idJogador].maoJogador[idPeca].esquerda = jogadores[idJogador].maoJogador[idPeca].direita;
                    jogadores[idJogador].maoJogador[idPeca].direita = aux;
                    campo.pecas[campo.tam - 1] = jogadores[idJogador].maoJogador[idPeca];
                    // Após isso, a peça jogada foi copiada para a posição 0 do campo
                    // CHAMAR A FUNÇÃO DE REMOVER A PEÇA DA MÃO
                    diminuirMao(idPeca, idJogador);
                }
                else
                {
                    campo.tam--;
                    campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
                    printf("Jogada invalida, escolha uma peça correta\n");
                    printf("A peça que voçe tentou jogar foi: [%d][%d], comparando com [%d][%d]\n",jogadores[idJogador].maoJogador[idPeca].esquerda,jogadores[idJogador].maoJogador[idPeca].direita,campo.pecas[campo.tam - 1].esquerda,campo.pecas[campo.tam - 1].direita);
                    system("pause");
                    return 0;
                }
            }
        }
    }
    return 1;
}

void comprarPecas(int idJogador)
{
    // Função responsável por executar uma compra de uma peça por parte do jogador
    int tamanMao, tamBanco = banco.tam;
    if (banco.tam == 0)
    {
        printf("O banco esta vazio!");
        return;
    }
    else
    {
        jogadores[idJogador].tamMao++;
        tamanMao = jogadores[idJogador].tamMao;
        jogadores[idJogador].maoJogador = realloc(jogadores[idJogador].maoJogador, tamanMao * sizeof(pecaDomino));
        jogadores[idJogador].maoJogador[tamanMao - 1] = banco.pecas[0];
        for (int i = 0; i < tamBanco - 1; i++)
        {
            banco.pecas[i].esquerda = banco.pecas[i + 1].esquerda;
            banco.pecas[i].direita = banco.pecas[i + 1].direita;
        }
        removerPeca(banco.pecas, &banco.tam);
    }
}

void distribuirMao(int idJogador)
{
    // Função responsável por distribuir as peças do jogo para a mão dos jogadores
    for (int i = 0; i < 7; i++)
    {
        comprarPecas(idJogador);
    }
}

void passaVez(int *idJogador)
{
    // Função responsável por passar a vez de um jogador para outro
    int tamanBanco = banco.tam;
    if (tamanBanco == 0)
    {
        if (*idJogador == 0)
        {
            *idJogador = 1;
        }
        else
        {
            *idJogador = 0;
        }
    }
}

void imprimirCampo()
{
    for (int i = 0; i < campo.tam; i++)
    {                                                                       // Laço de repetição que itera todos os elemento do vetor campo
        printf("[%i|%i]", campo.pecas[i].esquerda, campo.pecas[i].direita); // Imprime as peÃ§as presentes no campo até então
    }
}

int pecaInicial()
{
    int contador1E = -1, contador1D = -1, indice1;
    int contador2E = -1, contador2D = -1, indice2;
    // Caso 1, para comparar as peças iguais dos jogador e ver qual deles tem a maior
    for (int i = 0; i < 7; i++)
    {
        if (jogadores[0].maoJogador[i].esquerda == jogadores[0].maoJogador[i].direita)
        { // Caso em que o jogador possui peça dupla
            if (jogadores[0].maoJogador[i].esquerda > contador1E)
            {
                contador1E = jogadores[0].maoJogador[i].esquerda; // Armazena o maior valor encontrado nas peças
                contador1D = jogadores[0].maoJogador[i].direita;
                indice1 = i;
            }
        }
        if (jogadores[1].maoJogador[i].esquerda == jogadores[1].maoJogador[i].direita)
        {
            if (jogadores[1].maoJogador[i].esquerda > contador2E)
            {
                contador2E = jogadores[1].maoJogador[i].esquerda;
                contador2D = jogadores[1].maoJogador[i].direita;
                indice2 = i;
            }
        }
    }
    if (contador1D > contador2D)
    {
        printf("O PRIMEIRO jogador tinha a dupla [%d|%d], logo ele comecou jogando!\n", contador1D, contador1D);
        campo.tam++;
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
        campo.pecas[0] = jogadores[0].maoJogador[indice1];
        diminuirMao(indice1, 0);
        return 1;
    }
    else if (contador2D > contador1D)
    {
        printf("O SEGUNDO jogador tinha a dupla [%d|%d], logo ele comecou jogando!\n", contador2D, contador2D);
        campo.tam++;
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
        campo.pecas[0] = jogadores[1].maoJogador[indice2];
        diminuirMao(indice2, 1);
        return 0;
    }

    int maiorJogador1 = -1, maiorJogador2 = -1, soma; // Inicializa variáveis para armazenar a maior soma de peças de cada jogador
    // Verifica a maior soma de peças para o jogador 1
    for (int i = 0; i < jogadores[0].tamMao; i++)
    {
        soma = jogadores[0].maoJogador[i].esquerda + jogadores[0].maoJogador[i].direita;
        if (soma > maiorJogador1)
        {
            maiorJogador1 = soma;
        }
        soma = jogadores[1].maoJogador[i].esquerda + jogadores[1].maoJogador[i].direita;
        if (soma > maiorJogador2)
        {
            maiorJogador2 = soma;
        }
    }

    // Caso nenhum jogador tenha peças duplas, compara as maiores somas
    if (maiorJogador1 > maiorJogador2)
    {
        return 0;
    }
    else if (maiorJogador2 > maiorJogador1)
    {
        return 1;
    }
    else
    {
        return 1;
        // Verifica a maior peça entre os jogadores se as somas forem iguais
        // (código similar ao anterior para comparar peças individuais)
    }
}