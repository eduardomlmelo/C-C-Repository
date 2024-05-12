#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { // Definição da estrutura da peça, por meio de uma struct, de nome 'pecaDomino'
    int esquerda; // Cria-se os campos para os números da esquerda e da direita, respectivamente
    int direita;
} pecaDomino;

typedef struct { // Definição do tipo de struct 'jogador', atribuindo os campos abaixo
    pecaDomino *maoJogador; // Campo do tipo 'pecaDomino'
    int tamMao;             // Campo do tipo inteiro para armazenar o tamanho da mão do jogador
} jogador;

typedef struct { // Definição de tipo de struct 'bancoPecas' que servirá para armazenar as peças do banco
    pecaDomino *pecas;  // Campo do tipo 'pecaDomino' para armazenar as peças, propriamente ditas
    int tam;            // Campo do tipo inteiro para armazenar o tamanho do banco
} bancoPecas;

typedef struct {
    pecaDomino pecasC[28]
} campoPecas;

// Variáveis GLOBAIS que serão utilizadas regularmente no código, a fim de facilitar posteriores usos
jogador jogadores[2]; // Vetor GLOBAL do tipo jogador, para armazenar as informações dos jogadores, como qnt de peças, tamanho da mão e peças na mão
bancoPecas banco;     // Variável GLOBAL do tipo bancoPecas, para armazenar as informações do banco, como qnt de peças no banco e quais peças estão no banco
campoPecas campo;     // Variável GLOBAL do tipo bancoPecas, para armazenar as informções do campo, como tamanho do campo e quais peças estão no campo
pecaDomino *pecaJogo; // Ponteiro GLOBAL do tipo pecaDomino, para armazenas todas as peças do jogo. Seu uso será para a criação das peças do jogo

int JogadorAtual; // Variável GLOBAL cuja função é determinar qual jogador está jogando no momento

void gerador() {    
    // Função responsável por gerar todas as peças do jogo
     int indice = 0;                        // Inicializa variável 'indice' que será usada para percorrer todos os elementos do vetor recebido como parâmetro
     for (int i = 0; i <= 6; i++) {         // Inicia o laço de fora com i=0, que atribuirá os valores de 0 a 6 aos '.esquerda' das peças
         for (int j = i; j <= 6; j++) {     // Inicia o laço de dentro com j=i, para, dessa forma, não gerar peças repetidas. Pois, 'j' sempre começará em i
             pecaJogo[indice].esquerda = i; // Atribui ao '.esquerda' do elemento atual o valor do 'i' atual
             pecaJogo[indice].direita = j;  // Similar ao anterior, atribui, agora, o '.direita'
             indice++;                      // Incrementa o 'indice', após cada atribuição completa de peça, para preencher todo o vetor
         }
     }
}


void gerarBanco() {
    //Função responsável por gerar o banco de peças para compra
     for (int i = 0; i < 14; i++) {                             // Inicia o laço de repetição para iterar todas as posições do vetor 'campo'
         banco.pecas[i].esquerda = pecaJogo[14 + i].esquerda;   // Atribui à peça 'i' do banco.esquerda o valor da peça '14+i' do vetor que contém todas as peças
         banco.pecas[i].direita = pecaJogo[14 + i].direita;     // Ou seja, as peças do banco começam a partir da 14° do pecasJogo
     }
     banco.tam = 14; // Atribui ao campo 'tam' da struct 'banco' o valor de 14
}


void embaralhador() {
    // Função reponsável por embaralhar todas as peças do jogo
     for (int i = 0; i < 28; i++) {           // Inicia o laço de fora que percorrerá todo o vetor recebido como parâmetro
         int aleatorio = rand() % 27;         // Atribui à variável 'aleatorio', um índice aleatório do vetor parâmetro
         pecaDomino temp = pecaJogo[i];       // Atribui à temporária, o elemento atual determinado pelo laço
         pecaJogo[i] = pecaJogo[aleatorio];   // Atribui ao elemento atual outro elemento, de índice 'aleatorio'
         pecaJogo[aleatorio] = temp;          // Atribui a esse elemento[aleatorio] o valor contido em 'temp'
     }
}


void distribuirMao(int idJogador) {
    //Função responsável por distribuir as peças do jogo para a mão dos jogadores
     for (int i = 0; i < 7; i++) {
        jogadores[idJogador-1].maoJogador[i].esquerda = pecaJogo[i].esquerda; // Atrbui ao '.esquerda' do jogador o '.esquerda' do pecasJogo
        jogadores[idJogador-1].maoJogador[i].direita = pecaJogo[i].direita;   // Similar ao anterior, agora atribui o'.direita'
     }
     jogadores[idJogador-1].tamMao = 7; // Atribui ao campo 'tamMao', do elemento jogadores[idJogador-1] do vetor de struct, o valor 7
} // Vale ressaltar que, para maior efetividade no jogo, deve-se ultilizar a função 'embaralhador' antes desta


void removerNumeroVetor(pecaDomino *vetor, int *tam) {
    //Função responsável por diminuir o tamanho do banco de peças
    (*tam)--; // Diminui o conteúdo apontado por '*tam', ou seja, o valor da variável, em -1 unidade

    if(*tam == 0){ // Condicional que analisa o caso do tamanho se igual a 0
        free(vetor); // Nesse caso, ele realoca memória ocupada pela variável, liberando o espaço da memória
    }
    else if(vetor != NULL){ // Caso não, realiza uma realocação de memória, agora com o tamanho diminuído em -1
        realloc(vetor, (*tam) * sizeof(pecaDomino)); // Ultiliza a função 'realoc' para redimensionar o vetor passado por parâmetro
    }
}


int jogada(int idPeca, int idJogador, int qualLado){
int daPraJogar = podeJogar(idPeca, idJogador, qualLado);
if(daPraJogar == 0){
    printf("Jogada invalida!!!");
    return 0;
}else if (daPraJogar == 1){ // Jogar peça NORMAL
    if(qualLado == 0){ // Jogar peça na ESQUERDA do campo
        for(int i=0;i<27;i--){ // Laço que copia todas as peças para uma posição a frente
        if(campo.pecasC[i+1].esquerda != 7){
            campo.pecasC[i+1].esquerda = campo.pecasC[i].esquerda;
            campo.pecasC[i+1].direita = campo.pecasC[i].direita;
            }
        }
        campo.pecasC[0].esquerda = jogadores[idJogador-1].maoJogador[idPeca].esquerda;
        campo.pecasC[0].direita = jogadores[idJogador-1].maoJogador[idPeca].direita;
    }else if (qualLado == 1){ // Jogar peça na DIREITA
    int contador = 0;
        for(int i=0;i<28;i++){
            if (campo.pecasC[i].esquerda != 7 || campo.pecasC[i].direita != 7){
                contador++;
            }
        }
        campo.pecasC[contador].esquerda = jogadores[idJogador-1].maoJogador[idPeca].esquerda;
        campo.pecasC[contador].direita = jogadores[idJogador-1].maoJogador[idPeca].direita;
    }

}else if (daPraJogar == 2){ // Jogar peça INVERTIDA
    if(qualLado == 0){ // Jogar peça na ESQUERDA do campo
        for(int i=26;i=0;i--){ // Laço que copia todas as peças para uma posição a frente
            campo.pecasC[i+1].esquerda = campo.pecasC[i].esquerda;
            campo.pecasC[i+1].direita = campo.pecasC[i].direita;
            }
        campo.pecasC[0].esquerda = jogadores[idJogador-1].maoJogador[idPeca].direita;
        campo.pecasC[0].direita = jogadores[idJogador-1].maoJogador[idPeca].esquerda;
    }else if (qualLado == 1){ // Jogar peça na DIREITA
    int contador = 0;
        for(int i=0;i<28;i++){
            if (campo.pecasC[i].esquerda != 7 || campo.pecasC[i].direita != 7){
                contador++;
            }
        }
        campo.pecasC[contador].esquerda = jogadores[idJogador-1].maoJogador[idPeca].direita;
        campo.pecasC[contador].direita = jogadores[idJogador-1].maoJogador[idPeca].esquerda;
    }
}

} 


int podeJogar(int idPeca,int idJogador,int qualLado){
if(qualLado == 0){ // Jogar peça na ESQUERDA
    if(campo.pecasC[0].esquerda == jogadores[idJogador-1].maoJogador[idPeca].direita){
        return 1;
    }else if (campo.pecasC[0].esquerda == jogadores[idJogador-1].maoJogador[idPeca].esquerda){
        return 2;
    }else{
        return 0;
    }
}else if (qualLado == 1){ // Jogar peça na DIREITA
    int contador=0;
    for(int i=0;i<28;i++){
            if (campo.pecasC[i].esquerda != 7 || campo.pecasC[i].direita != 7){
                contador++;
            }
        }
    if(campo.pecasC[contador].direita == jogadores[idJogador-1].maoJogador[idPeca].esquerda){
        return 1;
    }else if (campo.pecasC[contador].direita == jogadores[idJogador-1].maoJogador[idPeca].direita){
        return 2;
    }else{
        return 0;
    }
}
}


void comprarPecas(int idJogador){
    // Função responsável por executar uma compra de uma peça por parte do jogador
     int tamanMao, tamBanco = banco.tam; // Declara a variável tamanMao e inicializa tamBanco como o valor de banco.tam, no intuito de facilitar a comprensão do código e sua utilização 
             if (banco.tam == 0) { // COndicional que verifica se há peças disponíveis para compra
                printf("Nao ha mais pecas para comprar\n"); // Caso não, printa a mensagem de banco vazio na tela
             }
            else { // Caso sim, executa a sequência de comandos para adicionar uma peça na mão do jogador e diminuir o tamanho do banco
                 jogadores[idJogador-1].tamMao++; // Aumenta em uma unidade o valor do campo tamMao, ou seja, aumenta em 1 o tamanho da mão do jogador
                 tamanMao = jogadores[idJogador-1].tamMao; // Incializa a variável tamanMao com o valor do tamanho da mão do jogador, no intuito de facilitar o código
                 jogadores[idJogador-1].maoJogador = realloc(jogadores[idJogador-1].maoJogador, tamanMao*sizeof(pecaDomino)); // Realoca o vetor da mão do jogador, ajustando para o novo tamanho da mão, acrescido de +1
                 jogadores[idJogador-1].maoJogador[tamanMao-1].esquerda = banco.pecas[0].esquerda; // Atribui à nova peça da mão a peça de posição 0 do vetor banco
                 jogadores[idJogador-1].maoJogador[tamanMao-1].direita = banco.pecas[0].direita;
                 for(int i = 0; i < tamBanco-1; i++){ // Laço de repetição que cria uma cópia de cada peça do banco para uma posição anterior, deixando uma 'repetida' na última posição
                    banco.pecas[i].esquerda = banco.pecas[i+1].esquerda;
                    banco.pecas[i].direita = banco.pecas[i+1].direita;
                 }
                 removerNumeroVetor(banco.pecas, &banco.tam); // Chama a função para remover o último elemento vetor 'banco' e diminuir seu tamanho em -1 unidade
            }
}

void passaVez(int *idJogador) {
    //Função responsável por passar a vez de um jogador para outro
    int tamanBanco = banco.tam; // Inicializa a variável tamanBanco com o valor do campo '.tam' da variável struct 'banco'
    if (tamanBanco == 0) {      // Condicional responsável por avaliar qual jogador está jogando no momento
        if (*idJogador == 1) {  // Caso seja o Jogador1, ele re-atribui a variável 'idJogador' com o id do próximo jogador
            *idJogador = 2;
        }
        else {
             *idJogador = 1;    // Similar ao anterior, agora para o inverso
        }

    }
    
}

void imprimirCampo(){
    // Função responsável por imprimir na tela as peças atuais no campo
     for (int i = 0; i < 28; i++) {                                     // Laço de repetição que itera todos os elemento do vetor campo
         printf("[%i][%i]", campo.pecasC[i].esquerda, campo.pecasC[i].direita);  // Imprime as peças presentes no campo até então
     }
}

/*void imprimirCampof(){
    for (int i = 0; i < 28; i++){
        if(campo.pecasC[i].esquerda != 7 || campo.pecasC[i].direita != 7){
            printf("[%i][%i]",campo.pecasC[i].esquerda,campo.pecasC[i].direita);
        }
    }
}*/

void imprimirMao(int idJogador) { 
    // Função responsável por imprimir no console as peças do jogador selecionado
     int tamMao = jogadores[idJogador-1].tamMao; // Inicializa a variável 'tamMao' com o valor presente no '.tamMao' do elemento atual do vetor 'jogadores[]'
     printf("Mao do jogador %i\n", idJogador);

     if(idJogador == 1) { // Condicional que avalia a mão de qual jogador será impressa na tela
        for (int i = 0; i < tamMao; i++) { // Caso seja o Jogador1, inicia o laço de repetição para imprimir os elementos do vetor 'jogadores[id-1]'
            printf("%i: [%i][%i] ", i, jogadores[idJogador-1].maoJogador[i].esquerda, jogadores[idJogador-1].maoJogador[i].direita);
        }
     }

     if(idJogador == 2) {
        for (int i = 0; i < tamMao; i++) {
            printf("%i: [%i][%i] ", i, jogadores[idJogador-1].maoJogador[i].esquerda, jogadores[idJogador-1].maoJogador[i].direita);
        }
     }
     printf("\n");
}


int main(){
    srand(time(NULL));
    jogadores[0].maoJogador = malloc(7 * sizeof(pecaDomino));
    jogadores[1].maoJogador = malloc(7 * sizeof(pecaDomino));
    //campo.pecasC = malloc(1 * sizeof(pecaDomino));
    banco.pecas = malloc(14 * sizeof(pecaDomino));
    pecaJogo = malloc(28 * sizeof(pecaDomino));
    gerador();
    embaralhador();
    distribuirMao(1);
    distribuirMao(2);
    gerarBanco();
    gerarCampo();

    // campo.pecasC[0].esquerda = 6; //Teste
    // campo.pecasC[0].direita = 6;  //Teste
    // campo.tam++;

    campo.pecasC[0].esquerda = 6;
    campo.pecasC[0].direita = 6;

    printf("\n");
    int opcao, peca, qualLado;
    // Exemplo de jogada do jogador 1

    if (JogadorAtual != 1 && JogadorAtual != 2) {
        printf("Digite o jogador atual: ");
        scanf("%d", &JogadorAtual);
    }

    while (1) {
        printf("\nMESA ATUAL\n");
        imprimirCampo();
        // imprimirCampof();
        printf("\n");
        printf("MAO JOGADOR\n");
        imprimirMao(JogadorAtual);
        printf("\n");
        printf("1 para jogar uma peca\n");
        printf("2 para comprar do banco\n");
        printf("3 para passar a vez\n");
        printf("Digite uma opcao de escolha para fazer: ");
        scanf("%i", &opcao);
        if (opcao == 90)
        {
            printf("Codigo de erro selecionado. PARANDO PROGRAMA");
            break;
        }
        switch (opcao)
        {
        case 1:
            printf("Escolha um lado para jogar: ");
            scanf("%i",&qualLado);
            printf("Escolha uma peca para jogar: ");
            scanf("%i",&peca);
                while(peca >= jogadores[JogadorAtual-1].tamMao || peca < 0){
                    printf("A opcao digitada nao existe!\n");
                    printf("Digite uma opcao de peca  valida: ");
                    scanf("%i", &peca);
                }
            podeJogar(peca,JogadorAtual,qualLado);
            jogada(peca,JogadorAtual,qualLado);
            break;
        case 2:
             comprarPecas(JogadorAtual);
             break;
        case 3:
             passaVez(&JogadorAtual);
             break;
        default:
             printf("Digite uma opcao de escolha valida!\n");
             break;
        }
        system("cls");
    }
    free(jogadores[0].maoJogador);
    free(jogadores[1].maoJogador);
    //free(campo.pecasC);
    free(banco.pecas);
    free(pecaJogo);
}