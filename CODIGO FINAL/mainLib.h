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

int JogadorAtual, adversario;

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
    int tamMao = jogadores[idJogador].tamMao;     // Inicializa a vari�vel 'tamMao' com o valor do tamanho da m�o do jogador atual, para facilitar o manuseio
    printf("M�o do jogador %i\n", idJogador + 1); // Imprime na tela a mensagem indicando de qual jogador � a m�o impressa
    // Vale ressaltar que deve-se somar +1 ao �ndice 'idJogador', pois o mesmo varia de 0-1
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
    // Fun��o respons�vel por diminuir a quantidade de pe�as
    (*tam)--; // Diminui o conte�do apontado por '*tam' em -1

    if (*tam == 0) // Se o tamanho for reduzido a 0, libera mem�ria alocada pelo ponteiro
    {
        free(vetor);
    }
    else if (vetor != NULL) // Caso n�o, realoca a mem�ria alocada pelo ponteiro, agora com o tamanho reduzido
    {
        realloc(vetor, (*tam) * sizeof(pecaDomino));
    }
}

void diminuirMao(int idPeca, int idJogador)
// Fun��o respons�vel remover a pe�a jogada por um jogador e reduzir o tamanho da m�o do mesmo
{
    for (int i = idPeca; i < jogadores[idJogador].tamMao; i++) // Loop respons�vel por copiar todas as pe�as, a partir da posi��o seguinte da pe�a jogada, para uma posi��o anterior
    {
        jogadores[idJogador].maoJogador[i] = jogadores[idJogador].maoJogador[i + 1];
    }
    removerPeca(jogadores[idJogador].maoJogador, &jogadores[idJogador].tamMao); // Chama a fun��o para remover a �ltima pe�a do vetor m�o, que � uma c�pia da pen�ltima
}

int podeJogar(int idPeca, int idJogador, int qualLado)
// Fun��o respons�vel por avaliar as condi��es e determinar se � poss�vel jogar uma pe�a no campo
{
    if (qualLado != 0 && qualLado != 1)
    { // Condicional que avalia se a op��o selecionada � diferente das op��es v�lidas
        printf("Lado inv�lido, Digite uma op��o dispon�vel\n");
        system("pause"); // Caso n�o, escreve a mensagem na tela e termina a execu��o da fun��o
        return 0;
    }
    if (qualLado == 0)
    {                // Jogar pe�a na ESQUERDA do campo
        campo.tam++; // Aumenta em +1 o valor da vari�vel e realoca mem�ria, de acordo com o novo tamanho
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
        if (campo.pecas[0].esquerda == jogadores[idJogador].maoJogador[idPeca].direita)
        { // Pe�a do jogador encaixa normalmente no campo
            for (int i = campo.tam - 2; i >= 0; i--)
            {
                campo.pecas[i + 1].esquerda = campo.pecas[i].esquerda;
                campo.pecas[i + 1].direita = campo.pecas[i].direita;
            } // Loop para copiar todas as pe�as do campo para uma posi��o a frente
            campo.pecas[0] = jogadores[idJogador].maoJogador[idPeca];
            // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
            // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
            diminuirMao(idPeca, idJogador);
            // Copia a pe�a jogada para a posi��o vazia mais � direita do campo, determinada pelo loop anterior
        }
        else
        {
            if (campo.pecas[0].esquerda == jogadores[idJogador].maoJogador[idPeca].esquerda)
            { // Pe�a do jogador deve ser invertida para encaixar
                for (int i = campo.tam - 2; i >= 0; i--)
                {
                    campo.pecas[i + 1].esquerda = campo.pecas[i].esquerda;
                    campo.pecas[i + 1].direita = campo.pecas[i].direita;
                } // Loop para copiar todas as pe�as do campo para uma posi��o a frente
                campo.pecas[0].esquerda = jogadores[idJogador].maoJogador[idPeca].direita;
                campo.pecas[0].direita = jogadores[idJogador].maoJogador[idPeca].esquerda; // Inverte a pe�a jogada e copia na posi��o 0 do campo
                // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
                // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
                diminuirMao(idPeca, idJogador);
                // Copia a pe�a jogada para a posi��o vazia mais � direita do campo, determinada pelo loop anterior
            }
            else
            { // Caso a pe�a n�o possa ser jogada na esquerda, diminui o valor da vari�vel em -1 e realoca mem�ria
                campo.tam--;
                campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
                printf("Jogada inv�lida, escolha uma pe�a correta\n");
                printf("A pe�a que vo�e tentou jogar foi: [%d|%d], comparando com [%d|%d]\n", jogadores[idJogador].maoJogador[idPeca].esquerda, jogadores[idJogador].maoJogador[idPeca].direita, campo.pecas[0].esquerda, campo.pecas[0].direita);
                system("pause");
                return 0; // No caso citado, a fun��o retorna 0, para indicar que houve erro na jogada
            }
        }
    }
    else
    {
        if (qualLado == 1)
        { // Jogar pe�a na DIREITA do campo
            campo.tam++;
            campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
            if (campo.pecas[campo.tam - 2].direita == jogadores[idJogador].maoJogador[idPeca].esquerda)
            { // Pe�a encaixa normalmente no campo
                campo.pecas[campo.tam - 1] = jogadores[idJogador].maoJogador[idPeca];
                // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
                // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
                diminuirMao(idPeca, idJogador);
                // Copia a pe�a jogada para a posi��o vazia mais � direita do campo, determinada pelo loop anterior
            }
            else
            {
                if (campo.pecas[campo.tam - 2].direita == jogadores[idJogador].maoJogador[idPeca].direita)
                { // Pe�a deve ser invertida para encaixar no campo
                    int aux;
                    aux = jogadores[idJogador].maoJogador[idPeca].esquerda;
                    jogadores[idJogador].maoJogador[idPeca].esquerda = jogadores[idJogador].maoJogador[idPeca].direita;
                    jogadores[idJogador].maoJogador[idPeca].direita = aux;
                    campo.pecas[campo.tam - 1] = jogadores[idJogador].maoJogador[idPeca];
                    // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
                    // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
                    diminuirMao(idPeca, idJogador);
                }
                else
                {
                    campo.tam--; // Caso a pe�a n�o possa ser jogada na esquerda, diminui o valor da vari�vel em -1 e realoca mem�ria
                    campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino));
                    printf("Jogada invalida, escolha uma pe�a correta\n");
                    printf("A pe�a que vo�e tentou jogar foi: [%d|%d], comparando com [%d|%d]\n", jogadores[idJogador].maoJogador[idPeca].esquerda, jogadores[idJogador].maoJogador[idPeca].direita, campo.pecas[campo.tam - 1].esquerda, campo.pecas[campo.tam - 1].direita);
                    system("pause");
                    return 0; // No caso citado, a fun��o retorna 0, para indicar que houve erro na jogada
                }
            }
        }
    }
    return 1; // Para o caso da pe�a ter sido jogada corretamente, a fun��o retorna 1, para indicar que houve sucesso na jogada
}

void comprarPecas(int idJogador)
{
    // Fun��o respons�vel por executar uma compra de uma pe�a por parte do jogador
    int tamanMao, tamBanco = banco.tam;
    if (banco.tam == 0)
    {
        printf("O banco esta vazio!\n");
        system("pause");
        return;
    }
    else
    {
        jogadores[idJogador].tamMao++;                                                                             // Aumenta em +1 o valor da vari�vel
        tamanMao = jogadores[idJogador].tamMao;                                                                    // Atribui o valor campo '.tamMao' � vari�vel 'tamanMan', para facilitar o manuseio
        jogadores[idJogador].maoJogador = realloc(jogadores[idJogador].maoJogador, tamanMao * sizeof(pecaDomino)); // Realoca mem�ria do campo '.maoJogador', agora com o valor correspondente da vari�vel 'tamanMao'
        jogadores[idJogador].maoJogador[tamanMao - 1] = banco.pecas[0];                                            // Atribui � pe�a da �ltima posi��o da m�o do jogador, at� ent�o contendo lixo, os valores dos campos do vetor banco[0]
        for (int i = 0; i < tamBanco - 1; i++)
        { // Loop respons�vel por copiar todas as pe�as do banco, a partir da posi��o '1', uma posi��o anterior
            banco.pecas[i].esquerda = banco.pecas[i + 1].esquerda;
            banco.pecas[i].direita = banco.pecas[i + 1].direita;
        }                                     // Ao fim do loop, a �ltima posi��o do vetor e a pen�ltima ficam com valores iguais, ou seja, pe�as repetidas
        removerPeca(banco.pecas, &banco.tam); // Chama a fun��o para remover a pe�a repetida do vetor
    }
}

void distribuirMao(int idJogador)
{
    // Fun��o respons�vel por distribuir as pe�as, no in�cio do jogo, para a m�o dos jogadores
    for (int i = 0; i < 7; i++)
    {
        comprarPecas(idJogador); // Para cada posi��o da m�o inicial do jogador em quest�o, adiciona uma pe�a do vetor banco
    }
}

int passaVez(int *idJogador)
{
    // Fun��o respons�vel por passar a vez de um jogador para outro
    int tamanBanco = banco.tam;
    if (tamanBanco == 0) // Avalia se o tamanho do vetor 'banco' � igual a 0, sendo essa a condi��o necess�ria para ser poss�vel passar a vez
    {
        if (*idJogador == 0) // Condicional respons�vel por avaliar de qual jogador � a rodada
        {
            *idJogador = 1; // Atribui o valor do pr�ximo jogador � vari�vel 'idJogador'
            adversario = 1; // Semelhante ao anterior, agora atribui para o 'advers�rio'
        }
        else
        {
            *idJogador = 0;
            adversario = 2;
        }
    }
    else
    {
        printf("Puxe at� achar uma pe�a que possa ser jogada. S� pode passar quando as pe�as do banco chegarem a 0.\n");
        system("pause");
        return 0;
    }
    return 0;
}

void imprimirCampo()
{ // Fun��o respons�vel por imprimir na tela as pe�as presentes no campo
    for (int i = 0; i < campo.tam; i++)
    {                                                                       // La�o de repeti��o que itera todos os elemento do vetor campo
        printf("[%i|%i]", campo.pecas[i].esquerda, campo.pecas[i].direita); // Imprime as peças presentes no campo at� ent�o
    }
}

int pecaInicial()
{ // Fun��o respons�vel por avaliar as pe�as dos dois jogadores e determinar qual deles tem a pe�a de maior valor e, portanto, quem jogar� primeiro
    int contador1E = -1, contador1D = -1, indice1;
    int contador2E = -1, contador2D = -1, indice2;
    // Caso 1, para comparar as pe�as duplas dos jogador e ver qual deles tem a maior
    for (int i = 0; i < 7; i++)
    {
        if (jogadores[0].maoJogador[i].esquerda == jogadores[0].maoJogador[i].direita)
        { // Caso em que o jogador possui pe�a dupla
            if (jogadores[0].maoJogador[i].esquerda > contador1E)
            {
                contador1E = jogadores[0].maoJogador[i].esquerda; // Armazena o maior valor encontrado nas pe�as
                contador1D = jogadores[0].maoJogador[i].direita;
                indice1 = i; // Armazena o valor do �ndice da maior pe�ar do jogador em quest�o
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
    if (contador1D > contador2D) // Condicional que avalia se o jogador 1 possui a maior pe�a
    {
        printf("O PRIMEIRO jogador tinha a dupla [%d|%d], logo ele comecou jogando!\n", contador1D, contador1D);
        campo.tam++;                                                        // Aumenta o valor da vari�vel
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino)); // Aumenta o tamanho do campo, inicialamente igual a 0, para o tamanho correspondente
        campo.pecas[0] = jogadores[0].maoJogador[indice1];                  // Atribui � posi��o 0 do campo o valor da maior pe�a do jogador
        diminuirMao(indice1, 0);                                            // Chama a fun��o para remover a pe�a jogada, de acordo com o �ndice armazenado anteriormente
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

    int maiorJogador1 = -1, maiorJogador2 = -1, soma; // Inicializa vari�veis para armazenar a maior soma de pe�as de cada jogador
    // Verifica a maior soma de pe�as para ambos os jogadores
    for (int i = 0; i < jogadores[0].tamMao; i++)
    {
        soma = jogadores[0].maoJogador[i].esquerda + jogadores[0].maoJogador[i].direita;
        if (soma > maiorJogador1)
        {
            maiorJogador1 = soma;
            indice1 = i;
        }
        soma = jogadores[1].maoJogador[i].esquerda + jogadores[1].maoJogador[i].direita;
        if (soma > maiorJogador2)
        {
            maiorJogador2 = soma;
            indice2 = i;
        }
    }

    // Caso nenhum jogador tenha pe�as duplas, compara as maiores somas
    if (maiorJogador1 > maiorJogador2)
    {
        printf("O PRIMEIRO jogador tinha a pe�a [%d|%d], logo ele comecou jogando!\n", jogadores[0].maoJogador[indice1].esquerda, jogadores[0].maoJogador[indice1].direita);
        campo.tam++;                                                        // Aumenta o valor da vari�vel
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino)); // Aumenta o tamanho do campo, inicialamente igual a 0, para o tamanho correspondente
        campo.pecas[0] = jogadores[0].maoJogador[indice1];                  // Atribui � posi��o 0 do campo o valor da maior pe�a do jogador
        diminuirMao(indice1, 0);                                            // Chama a fun��o para remover a pe�a jogada, de acordo com o �ndice armazenado anteriormente
        return 1;
    }
    else if (maiorJogador2 > maiorJogador1)
    {
        printf("O SEGUNDO jogador tinha a pe�a [%d|%d], logo ele comecou jogando!\n", jogadores[1].maoJogador[indice2].esquerda, jogadores[1].maoJogador[indice2].direita);
        campo.tam++;                                                        // Aumenta o valor da vari�vel
        campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino)); // Aumenta o tamanho do campo, inicialamente igual a 0, para o tamanho correspondente
        campo.pecas[0] = jogadores[1].maoJogador[indice2];                  // Atribui � posi��o 0 do campo o valor da maior pe�a do jogador
        diminuirMao(indice2, 1);                                            // Chama a fun��o para remover a pe�a jogada, de acordo com o �ndice armazenado anteriormente
        return 0;
    }
    else
    {
        return 1;
        // Verifica a maior pe�a entre os jogadores se as somas forem iguais
        // (c�digo similar ao anterior para comparar pe�as individuais)
    }
}
void salvarJogo()
{
    // Fun��o respons�vel por salvar o jogo atual, armazenando as informa��es necess�rias em um arquivo '.txt'
    FILE *arquivo = fopen("savegame.txt", "w"); // Inicaliza o ponteiro do arquivo e verifica se foi aberto corretamente
    if (arquivo == NULL)
    {
        printf("Erro ao salvar o jogo.\n");
        return;
    }

    // Salve as informa��es necess�rias no arquivo
    fprintf(arquivo, "%d\n", JogadorAtual);
    fprintf(arquivo, "%d\n", adversario);
    fprintf(arquivo, "%d\n", jogadores[0].tamMao);
    fprintf(arquivo, "%d\n", jogadores[1].tamMao);
    fprintf(arquivo, "%d\n", campo.tam);
    fprintf(arquivo, "%d\n", banco.tam);

    for (int i = 0; i < campo.tam; i++)
    { // Printa no arquivo as pe�as presentes no campo atual
        fprintf(arquivo, "%d %d\n", campo.pecas[i].esquerda, campo.pecas[i].direita);
    }
    for (int i = 0; i < banco.tam; i++)
    { // Printa no arquivo as pe�as presentes no banco atual
        fprintf(arquivo, "%d %d\n", banco.pecas[i].esquerda, banco.pecas[i].direita);
    }

    for (int i = 0; i < jogadores[0].tamMao; i++)
    { // Printa no arquivo as pe�as presentes na m�o do PRIMEIRO jogador
        fprintf(arquivo, "%d %d\n", jogadores[0].maoJogador[i].esquerda, jogadores[0].maoJogador[i].direita);
    }
    for (int i = 0; i < jogadores[1].tamMao; i++)
    { // Printa no arquivo as pe�as presentes na m�o do SEGUNDO jogador
        fprintf(arquivo, "%d %d\n", jogadores[1].maoJogador[i].esquerda, jogadores[1].maoJogador[i].direita);
    }

    // Feche o arquivo
    fclose(arquivo);
    printf("Jogo salvo com sucesso.\n");
}
void carregarJogo()
{
    // Fun��o respons�vel por carregar o jogo, atribuindo os valores lidos do arquivo �s vari�veis correspondentes do programa
    FILE *arquivo = fopen("savegame.txt", "r");
    if (arquivo == NULL)
    {
        printf("Nenhum jogo salvo encontrado.\n");
        return;
    }
    // Carregue as informa��es do arquivo
    fscanf(arquivo, "%d\n", &JogadorAtual);
    fscanf(arquivo, "%d\n", &adversario);
    fscanf(arquivo, "%d\n", &jogadores[0].tamMao);
    fscanf(arquivo, "%d\n", &jogadores[1].tamMao);
    fscanf(arquivo, "%d\n", &campo.tam);
    fscanf(arquivo, "%d\n", &banco.tam);
    campo.pecas = realloc(campo.pecas, campo.tam * sizeof(pecaDomino)); // Realoca mem�ria para o vetor 'campo', de acordo com o valor lido do arquivo
    banco.pecas = realloc(banco.pecas, banco.tam * sizeof(pecaDomino)); // Realoca mem�ria para o vetor 'banco', de acordo com o valor lido do arquivo
    for (int i = 0; i < campo.tam; i++)
    {
        fscanf(arquivo, "%d %d\n", &campo.pecas[i].esquerda, &campo.pecas[i].direita); // Atribui �s pe�as lidas ao campo
    }
    for (int i = 0; i < banco.tam; i++)
    {
        fscanf(arquivo, "%d %d\n", &banco.pecas[i].esquerda, &banco.pecas[i].direita); // Agora, ao banco
    }

    for (int i = 0; i < jogadores[0].tamMao; i++)
    {
        fscanf(arquivo, "%d %d\n", &jogadores[0].maoJogador[i].esquerda, &jogadores[0].maoJogador[i].direita); // �s pe�as do jogador 1
    }
    for (int i = 0; i < jogadores[1].tamMao; i++)
    {
        fscanf(arquivo, "%d %d\n", &jogadores[1].maoJogador[i].esquerda, &jogadores[1].maoJogador[i].direita); // �s pe�as do jogador 2
    }

    // Feche o arquivo
    fclose(arquivo);
    printf("Jogo carregado com sucesso.\n");
}