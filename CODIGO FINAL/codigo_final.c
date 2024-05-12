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
        printf(" -------- DOMIN� --------\n");
        printf(" -------- MENU ----------\n");
        printf("1 - Come�ar Um Novo Jogo (Dois Jogadores)\n");
        printf("2 - Carregar Um Jogo Salvo\n");
        printf("3 - Regras Do Domino\n");
        printf("4 - Fechar o Jogo\n");

        printf("Escolha Uma Opc�o: ");
        scanf("%d", &escolha);

        while (getchar() != '\n' || escolha > 4 || escolha < 1)
        {
            printf("Digite uma opc�o v�lida: ");
            scanf("%d", &escolha);
            printf("\n");
        }

        switch (escolha)
        {
        case 1:
            printf("Come�ando Um Novo Jogo ..........\n");
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
            printf("1 - Jogar uma Pe�a\n");
            printf("2 - Comprar do Banco (Qtd: %d)\n", banco.tam);
            printf("3 - Passar Vez (Qnt de pe�as do advers�rio: %d)\n", jogadores[adversario - 1].tamMao);
            printf("4 - Salvar Partida\n");
            printf("5 - Voltar ao Menu Inicial\n");

            printf("Digite uma opc�o de escolha para fazer: ");
            scanf("%d", &opcao);

            while (getchar() != '\n' || opcao > 6 || opcao < 1)
            {
                printf("\nEntrada inv�lida. Tente novamente.\n");
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
                printf("C�digo de parada\n");
                system("cls");
                exit(1);
            }
            if (opcao == 6)
            {
                printf("Vo�e escolheu a op��o de hack!!!\n");
                system("pause");
                jogadores[JogadorAtual].tamMao = 1;
            }

            switch (opcao)
            {
            case 1:
                printf("Escolha uma pe�a para jogar: ");
                scanf("%d", &peca);

                while (getchar() != '\n' || peca + 1 > jogadores[JogadorAtual].tamMao || peca < 0)
                {
                    printf("Digite uma opc�o de pe�a v�lida: ");
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
                printf("Digite uma opc�o de escolha v�lida!\n");
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