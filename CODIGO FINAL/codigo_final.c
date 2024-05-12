#include "mainLib.h"

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
        banco.tam = 28;
        printf("----------------------------------------------\n");
        printf(" -------- DOMINÓ --------\n");
        printf(" -------- MENU ----------\n");
        printf("1 - Começar Um Novo Jogo (Dois Jogadores)\n");
        printf("2 - Carregar Um Jogo Salvo\n");
        printf("3 - Regras Do Domino\n");
        printf("4 - Fechar o Jogo\n");

        printf("Escolha Uma Opcão: ");
        scanf("%d", &escolha);

        while (getchar() != '\n' || escolha > 4 || escolha < 1)
        {
            printf("Digite uma opcão válida: ");
            scanf("%d", &escolha);
            printf("\n");
        }

        switch (escolha)
        {
        case 1:
            printf("Começando Um Novo Jogo ..........\n");
            gerador();
            embaralhador();
            distribuirMao(0);
            distribuirMao(1);
            JogadorAtual = pecaInicial();
            break;

        case 2:
            printf("Carregando Um Jogo Salvo ......\n");
            carregarJogo();
            break;

        case 3:
            printf("\n");
            printf("* O jogo começa com um conjunto de 28 peças únicas e diferentes, variando de [0|0] até [6|6].\n");
            printf("\n");
            printf("* Cada jogador começa comprando 7 peças.\n");
            printf("\n");
            printf("* O jogador inicial é o que possui a dupla mais alta. Se nenhum jogador possuir uma dupla, o que tiver a maior soma inicia. Em caso de empate na soma, o jogador com a peça de maior número em sua composição começa. \n");
            printf("\n");
            printf("* Em cada vez, o jogador deve realizar uma das três ações: jogar uma peça de sua mão, comprar peças da mesa até que seja possivel  jogar ou passar a vez, se todas as peças do banco estiverem esgotadas.\n");
            printf("\n");
            printf("* As regras para jogar uma peça da mão para a mesa são as seguintes: é permitido jogar peças que tenham um lado com o mesmo número do lado esquerdo da peça mais a esquerda jogada ou um lado com o mesmo número do lado direito da peça mais a direita. Se ambas as possibilidades forem o mesmo numero, o jogador pode escolher em que lado quer jogar a peça.\n");
            printf("\n");
            printf("* Após a jogada, a peça jogada deve se conectar a peça que estava em mesa pelo lado com o número em comum,  formando assim  uma sequência linear de peças.\n");
            printf("\n");
            system("pause");
            system("cls");
            continue;

        case 4:
            printf("Saindo Do Jogo\n");
            exit(0);
        default:
            printf("Opcão Invalida. Tente Novamente.\n");
            break;
        }

        if (JogadorAtual == 1)
        {
            adversario = 1;
        }
        else
        {
            adversario = 2;
        }
        system("pause");
        system("cls");
        int opcao, peca, qualLado;
        while (1)
        {
            printf("MESA ATUAL\n");
            imprimirCampo();
            printf("\n");
            imprimirMao(JogadorAtual);
            printf("\n");
            printf("1 - Jogar uma Peça\n");
            printf("2 - Comprar do Banco (Qtd: %d)\n", banco.tam);
            printf("3 - Passar Vez (Qnt de peças do adversário: %d)\n", jogadores[adversario - 1].tamMao);
            printf("4 - Salvar Partida\n");
            printf("5 - Voltar ao Menu Inicial\n");

            printf("Digite uma opcão de escolha para fazer: ");
            scanf("%d", &opcao);

            while (getchar() != '\n' || opcao > 6 || opcao < 1)
            {
                printf("\nEntrada inválida. Tente novamente.\n");
                system("pause");
                break;
            }

            if (opcao == 5)
            {
                printf("1");
                break;
            }
            if (opcao == 90)
            {
                printf("Código de parada\n");
                system("cls");
                exit(1);
            }
            if (opcao == 6)
            {
                printf("Voçe escolheu a opção de hack!!!\n");
                system("pause");
                jogadores[JogadorAtual].tamMao = 1;
            }

            switch (opcao)
            {
            case 1:
                printf("Escolha uma peça para jogar: ");
                scanf("%d", &peca);

                while (getchar() != '\n' || peca + 1 > jogadores[JogadorAtual].tamMao || peca < 0)
                {
                    printf("Digite uma opcão de peça válida: ");
                    scanf("%d", &peca);
                    printf("\n");
                }

                printf("Escolha um lado (0->esquerda)(1->direita): ");
                scanf("%d", &qualLado);
                int jogada = podeJogar(peca, JogadorAtual, qualLado);
                if (jogada == 0)
                {
                    break;
                }
                if (jogadores[JogadorAtual].tamMao == 0)
                {
                    printf("Jogador %i venceu\n", JogadorAtual + 1);
                    system("pause");
                    system("cls");
                    exit(0);
                }
                if (JogadorAtual == 1)
                {
                    JogadorAtual = 0;
                    adversario = 2;
                }
                else
                {
                    JogadorAtual = 1;
                    adversario = 1;
                }
                break;
            case 2:
                comprarPecas(JogadorAtual);
                break;
            case 3:
                passaVez(&JogadorAtual);
                break;
            case 4:
                salvarJogo();
                printf("O jogo foi salvo\n");
                system("pause");
                break;
            default:
                printf("Digite uma opcão de escolha válida!\n");
                break;
            }
            system("cls");
        }
        campo.tam = 0;
        jogadores[0].tamMao = 0;
        jogadores[1].tamMao = 0;
        free(jogadores[0].maoJogador);
        free(jogadores[1].maoJogador);
        free(campo.pecas);
        free(banco.pecas);
        system("cls");
    }

    return 0;
}