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
        {                                  // Inicia o la�o de dentro com j=i, para, dessa forma, n�o gerar pe�as repetidas. Pois, 'j' sempre come�ar� em i
            banco.pecas[indice].esquerda = i; // Atribui ao '.esquerda' do elemento atual o valor do 'i' atual
            banco.pecas[indice].direita = j;  // Similar ao anterior, atribui, agora, o '.direita'
            indice++;                      // Incrementa o 'indice', após cada atribui��o completa de pe�a, para preencher todo o vetor
        }
    }
}

void embaralhador()
{
    // Fun��o repons�vel por embaralhar todas as pe�as do jogo
    for (int i = 0; i < 28; i++)
    {                                      // Inicia o la�o de fora que percorrer� todo o vetor recebido como par�metro
        int aleatorio = rand() % 27;       // Atribui � vari�vel 'aleatorio', um �ndice aleat�rio do vetor par�metro
        pecaDomino temp = banco.pecas[i];     // Atribui � tempor�ria, o elemento atual determinado pelo la�o
        banco.pecas[i] = banco.pecas[aleatorio]; // Atribui ao elemento atual outro elemento, de �ndice 'aleatorio'
        banco.pecas[aleatorio] = temp;        // Atribui a esse elemento[aleatorio] o valor contido em 'temp'
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
    for (int i = idPeca; i < jogadores[idJogador].tamMao; i++){
        jogadores[idJogador].maoJogador[i] = jogadores[idJogador].maoJogador[i + 1];
    }
    jogadores[idJogador].tamMao--;
    removerPeca(jogadores[idJogador].maoJogador, &jogadores[idJogador].tamMao);
}

int podeJogar(int idPeca, int idJogador, int qualLado)
{
    if (qualLado == 0)
    { // Jogar pe�a na ESQUERDA do campo
        campo.tam++;
        if (campo.pecas[0].esquerda == jogadores[idJogador - 1].maoJogador[idPeca].direita)
        { // Pe�a do jogador encaixa normalmente no campo
            for (int i = campo.tam; i >= 0; i--)
            {
                campo.pecas[i + 1].esquerda = campo.pecas[i].esquerda;
                campo.pecas[i + 1].direita = campo.pecas[i].direita;
            } // Loop para copiar todas as pe�as do campo para uma posi��o a frente
            campo.pecas[0].esquerda = jogadores[idJogador - 1].maoJogador[idPeca].esquerda;
            campo.pecas[0].direita = jogadores[idJogador - 1].maoJogador[idPeca].direita;
            // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
            // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
        }
        else
        {
            if (campo.pecas[0].esquerda == jogadores[idJogador - 1].maoJogador[idPeca].esquerda)
            { // Pe�a do jogador deve ser invertida para encaixar
                for (int i = campo.tam; i >= 0; i--)
                {
                    campo.pecas[i + 1].esquerda = campo.pecas[i].esquerda;
                    campo.pecas[i + 1].direita = campo.pecas[i].direita;
                } // Loop para copiar todas as pe�as do campo para uma posi��o a frente
                campo.pecas[0].esquerda = jogadores[idJogador - 1].maoJogador[idPeca].direita;
                campo.pecas[0].direita = jogadores[idJogador - 1].maoJogador[idPeca].esquerda; // Inverte a pe�a jogada e copia na posi��o 0 do campo
                // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
                // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
            }
            else
            {
                printf("Jogada inv�lida");
                return 1;
            }
        }
    }
    else
    {
        if (qualLado == 1)
        { // Jogar pe�a na DIREITA do campo
            campo.tam++;
            campo.pecas = realloc(campo.pecas,campo.tam * sizeof(pecaDomino));
            if ((campo.pecas[campo.tam-2].direita = jogadores[idJogador].maoJogador[idPeca].esquerda))
            { // Pe�a encaixa normalmente no campo
                campo.pecas[campo.tam-1].esquerda = jogadores[idJogador].maoJogador[idPeca].esquerda;
                campo.pecas[campo.tam-1].direita = jogadores[idJogador].maoJogador[idPeca].direita;
                // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
                // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
                diminuirMao(idPeca, idJogador);
                // Copia a pe�a jogada para a posi��o vazia mais � direita do campo, determinada pelo loop anterior
            }
            else
            {
                if ((campo.pecas[campo.tam-2].direita = jogadores[idJogador - 1].maoJogador[idPeca].direita))
                { // Pe�a deve ser invertida para encaixar no campo
                    campo.pecas[campo.tam-1].esquerda = jogadores[idJogador - 1].maoJogador[idPeca].direita;
                    campo.pecas[campo.tam-1].direita = jogadores[idJogador - 1].maoJogador[idPeca].esquerda;
                    // Ap�s isso, a pe�a jogada foi copiada para a posi��o 0 do campo
                    // CHAMAR A FUN��O DE REMOVER A PE�A DA M�O
                    diminuirMao(idPeca, idJogador);
                }
                else
                {
                    printf("Jogada invalida");
                    return 1;
                }
            }
        }
    }
    return 0;
}

void comprarPecas(int idJogador)
{
    // Fun��o respons�vel por executar uma compra de uma pe�a por parte do jogador
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
        jogadores[idJogador].maoJogador[tamanMao-1] = banco.pecas[0];
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
    // Fun��o respons�vel por distribuir as pe�as do jogo para a m�o dos jogadores
    for (int i = 0; i < 7; i++)
    {
        comprarPecas(idJogador);
    }
}
void passaVez(int *idJogador)
{
    // Fun��o respons�vel por passar a vez de um jogador para outro
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
    {                                                                       // La�o de repeti��o que itera todos os elemento do vetor campo
        printf("[%i|%i]", campo.pecas[i].esquerda, campo.pecas[i].direita); // Imprime as peças presentes no campo at� ent�o
    }
}

int pecaInicial()
{
    int contador1E =-1, contador1D =-1, indice1;
    int contador2E =-1, contador2D =-1, indice2;
    // Caso 1, para comparar as pe�as iguais dos jogador e ver qual deles tem a maior
    for (int i = 0; i < 7; i++)
    {
        if (jogadores[0].maoJogador[i].esquerda == jogadores[0].maoJogador[i].direita)
        { // Caso em que o jogador possui pe�a dupla
            if (jogadores[0].maoJogador[i].esquerda > contador1E)
            {
                contador1E = jogadores[0].maoJogador[i].esquerda; // Armazena o maior valor encontrado nas pe�as
                contador1D = jogadores[0].maoJogador[i].direita;
                indice1=i;
            }
        }
        if (jogadores[1].maoJogador[i].esquerda == jogadores[1].maoJogador[i].direita)
        {
            if (jogadores[1].maoJogador[i].esquerda > contador2E)
            {
                contador2E = jogadores[1].maoJogador[i].esquerda;
                contador2D = jogadores[1].maoJogador[i].direita;
                indice2=i;
            }
        }
    }
    if (contador1D > contador2D){
        printf("O primeiro jogador tinha a dupla [%d|%d], logo ele comecou jogando!", contador1D,contador1D);
        campo.tam++;
        campo.pecas = realloc(campo.pecas,campo.tam * sizeof(pecaDomino));
        campo.pecas[0] = jogadores[0].maoJogador[indice1];
        diminuirMao(indice1, 0);
        return 1;
    }
    else if (contador2D > contador1D){
        printf("O segundo jogador tinha a dupla [%d|%d], logo ele comecou jogando!", contador2D,contador2D);
        campo.tam++;
        campo.pecas = realloc(campo.pecas,campo.tam * sizeof(pecaDomino));
        campo.pecas[0] = jogadores[1].maoJogador[indice2];
        diminuirMao(indice2, 1);
        return 0;
    }

    int maiorJogador1 = -1, maiorJogador2 = -1, soma; // Inicializa vari�veis para armazenar a maior soma de pe�as de cada jogador
    // Verifica a maior soma de pe�as para o jogador 1
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

    // Caso nenhum jogador tenha pe�as duplas, compara as maiores somas
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
        // Verifica a maior pe�a entre os jogadores se as somas forem iguais
        // (c�digo similar ao anterior para comparar pe�as individuais)
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int escolha;
    while (1)
    {
        srand(time(NULL));
        jogadores[0].maoJogador = malloc(7 * sizeof(pecaDomino));
        jogadores[1].maoJogador = malloc(7 * sizeof(pecaDomino));
        campo.pecas = malloc(0 * sizeof(pecaDomino));
        banco.pecas = malloc(28 * sizeof(pecaDomino));
        banco.tam=28;
        printf("----------------------------------------------\n");
        printf(" -------- DOMIN� --------\n");
        printf(" -------- MENU ----------\n");
        printf("1 - Come�ar Um Novo Jogo (Dois Jogadores)\n");
        printf("2 - Carregar Um Jogo Salvo\n");
        printf("3 - Regras Do Domino\n");
        printf("4 - Fechar o Jogo\n");

        printf("Escolha Uma Opc�o: ");

        if (scanf("%d", &escolha) == 0)
        {
            // Limpa o buffer de entrada
            while (getchar() != '\n')
                ;
            printf("Entrada inv�lida. Tente novamente.\n");
            system("pause");
            system("cls");
            continue;
        }
        switch (escolha)
        {
        case 1:
            printf("Come�ando Um Novo Jogo ..........\n");
            break;

        case 2:
            // Fun��o CarregarJogo
            printf("Carregando Um Jogo Salvo ......\n");
            break;

        case 3:
            printf("\n");
            printf("* O jogo come�a com um conjunto de 28 pe�as �nicas e diferentes, variando de [0|0] at� [6|6].\n");
            printf("\n");
            printf("* Cada jogador come�a comprando 7 pe�as.\n");
            printf("\n");
            printf("* O jogador inicial � o que possui a dupla mais alta. Se nenhum jogador possuir uma dupla, o que tiver a maior soma inicia. Em caso de empate na soma, o jogador com a pe�a de maior n�mero em sua composi��o come�a. \n");
            printf("\n");
            printf("* Em cada vez, o jogador deve realizar uma das tr�s a��es: jogar uma pe�a de sua m�o, comprar pe�as da mesa at� que seja possivel  jogar ou passar a vez, se todas as pe�as do banco estiverem esgotadas.\n");
            printf("\n");
            printf("* As regras para jogar uma pe�a da m�o para a mesa s�o as seguintes: � permitido jogar pe�as que tenham um lado com o mesmo n�mero do lado esquerdo da pe�a mais a esquerda jogada ou um lado com o mesmo n�mero do lado direito da pe�a mais a direita. Se ambas as possibilidades forem o mesmo numero, o jogador pode escolher em que lado quer jogar a pe�a.\n");
            printf("\n");
            printf("* Ap�s a jogada, a pe�a jogada deve se conectar a pe�a que estava em mesa pelo lado com o n�mero em comum,  formando assim  uma sequ�ncia linear de pe�as.\n");
            printf("\n");
            system("pause");
            system("cls");
            continue;

        case 4:
            printf("Saindo Do Jogo\n");
            exit(0);
        default:
            printf("Opc�o Invalida. Tente Novamente.\n");
            break;
        }
        gerador();
        embaralhador();
        distribuirMao(0);
        distribuirMao(1);
        JogadorAtual = pecaInicial();
        printf("\n");
        int opcao, peca, qualLado;
        while (1)
        {
            printf("MESA ATUAL\n");
            imprimirCampo();
            printf("\n");
            imprimirMao(JogadorAtual);
            printf("\n");
            printf("1 - Jogar uma Pe�a\n");
            printf("2 - Comprar do Banco (Qtd: %d)\n", banco.tam);
            printf("3 - Passar Vez\n");
            printf("4 - Salvar Partida\n");
            printf("5 - Voltar ao Menu Inicial\n");
            printf("Digite uma opc�o de escolha para fazer: ");

            if (scanf("%d", &opcao) == 0)
            {
                // Limpa o buffer de entrada
                while (getchar() != '\n');
                printf("Entrada inv�lida. Tente novamente.\n");
                system("pause");
                system("cls");
                continue;
            }

            if (opcao == 5)
            {
                printf("1");
                break;
            }

            switch (opcao)
            {
            case 1:
                printf("Escolha uma pe�a para jogar: ");
                scanf("%i", &peca);
                while (peca + 1 > jogadores[JogadorAtual].tamMao || peca < 0)
                {
                    printf("A opc�o digitada nao existe!\n");
                    system("pause");
                    printf("Digite uma opc�o de pe�a v�lida: ");
                    scanf("%i", &peca);
                }
                printf("Escolha um lado: ");
                scanf("%d", &qualLado);
                podeJogar(peca, JogadorAtual, qualLado);
                break;
            case 2:
                comprarPecas(JogadorAtual);
                break;
            case 3:
                passaVez(&JogadorAtual);
                break;
            case 4:
                // Fun��o SalvarJogo
                printf("O jogo foi salvo\n");
                system("pause");
                break;
            default:
                printf("Digite uma opc�o de escolha v�lida!\n");
                break;
            }
            system("cls");
        }
        campo.tam = 0;
        free(jogadores[0].maoJogador);
        free(jogadores[1].maoJogador);
        free(campo.pecas);
        free(banco.pecas);
        system("cls");
    }

    return 0;
}