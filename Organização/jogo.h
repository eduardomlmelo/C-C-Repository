#include"funcoes.h"

int podeJogar(int idPeca, int idJogador, int qualLado)
{
    if (qualLado == 0)
    { // Jogar peça na ESQUERDA do campo
        if (campo.pecas[0].esquerda == jogadores[idJogador].maoJogador[idPeca].direita)
        { // Peça do jogador encaixa normalmente no campo
            campo.tam++;
            campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
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
                campo.tam++;
                campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
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
            if (campo.pecas[campo.tam - 2].direita == jogadores[idJogador].maoJogador[idPeca].esquerda)
            { // Peça encaixa normalmente no campo
                campo.tam++;
                campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
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
                    campo.tam++;
                    campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
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
                    printf("Jogada invalida, escolha uma peça correta\n");
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


void distribuirMao(int idJogador)
{
    // Função responsável por distribuir as peças do jogo para a mão dos jogadores
    for (int i = 0; i < 7; i++)
    {
        comprarPecas(idJogador);
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