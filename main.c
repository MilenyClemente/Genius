#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <winuser.h>

//texto comum
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Negrito
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Underline
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//texto de alta intensidad
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//texto de alta intensidade em negrito
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

//reset
#define RESET   "\x1b[0m"


typedef struct no{
char *cor;
struct no *proximo;
int processed;
}No;

typedef struct{
No *topo;
char *cor;
}Cores;

void delay(int number_of_seconds)
{
// Converting time into milli_seconds
int milli_seconds = 1000 * number_of_seconds;

// Storing start time
clock_t start_time = clock();

// looping till required time is not achieved
while (clock() < start_time + milli_seconds);
}

int pontuacao = 0;
int max_points = 0;

void imprimirNome(){
printf(BBLK"Pontos: %d \n", pontuacao);
printf("Recorde: %d"RESET, max_points);
printf("\n");
printf(BHMAG"\t\t\t\t   _____   ______   _   _   _____   _    _    _____ \n");
printf("\t\t\t\t  / ____| |  ____| | \\ | | |_   _| | |  | |  / ____|\n");
printf("\t\t\t\t | |  __  | |__    |  \\| |   | |   | |  | | | (___  \n");
printf("\t\t\t\t | | |_ | |  __|   | . ` |   | |   | |  | |  \\___ \\ \n");
printf("\t\t\t\t | |__| | | |____  | |\\  |  _| |_  | |__| |  ____) | \n");
printf("\t\t\t\t  \\_____| |______| |_| \\_| |_____|  \\____/  |_____/ \n");
printf("\n\n\n"RESET);
printf("");
}
void imprimirNomeSemRecorde(){
printf(BHMAG"\t\t\t\t   _____   ______   _   _   _____   _    _    _____ \n");
printf("\t\t\t\t  / ____| |  ____| | \\ | | |_   _| | |  | |  / ____|\n");
printf("\t\t\t\t | |  __  | |__    |  \\| |   | |   | |  | | | (___  \n");
printf("\t\t\t\t | | |_ | |  __|   | . ` |   | |   | |  | |  \\___ \\ \n");
printf("\t\t\t\t | |__| | | |____  | |\\  |  _| |_  | |__| |  ____) | \n");
printf("\t\t\t\t  \\_____| |______| |_| \\_| |_____|  \\____/  |_____/ \n");
printf("\n\n\n"RESET);
printf("");
}
void imprimirAmarelo(){
printf("\n\n\n");
    printf(BYEL"\t\t\t\t     _                             _       \n");
    printf("\t\t\t\t    / \\   _ __ ___   __ _ _ __ ___| | ___  \n");
    printf("\t\t\t\t   / _ \\ | '_ ` _ \\ / _` | '__/ _ \\ |/ _ \\ \n");
    printf("\t\t\t\t  / ___ \\| | | | | | (_| | | |  __/ | (_) |\n");
    printf("\t\t\t\t /_/   \\_\\_| |_| |_|\\__,_|_|  \\___|_|\\___/ \n"RESET);
}
void imprimirVerde(){
printf("\n\n\n");
    printf(BGRN"\t\t\t,---.  ,---.   .-''-.  .-------.     ______         .-''-.   \n");
    printf("\t\t\t|   /  |   | .'_ _   \\ |  _ _   \\   |    _ `''.   .'_ _   \\  \n");
    printf("\t\t\t|  |   |  .'/ ( ` )   '| ( ' )  |   | _ | ) _  \\ / ( ` )   ' \n");
    printf("\t\t\t|  | _ |  |. (_ o _)  ||(_ o _) /   |( ''_'  ) |. (_ o _)  | \n");
    printf("\t\t\t|  _( )_  ||  (_,_)___|| (_,_).' __ | . (_) `. ||  (_,_)___| \n");
    printf("\t\t\t\\ (_ o._) /'  \\   .---.|  |\\ \\  |  ||(_    ._) ''  \\   .---. \n");
    printf("\t\t\t \\ (_,_) /  \\  `-'    /|  | \\ `'   /|  (_.\\.' /  \\  `-'    / \n");
    printf("\t\t\t  \\     /    \\       / |  |  \\    / |       .'    \\       /  \n");
    printf("\t\t\t   `---`      `'-..-'  ''-'   `'-'  '-----'`       `'-..-'   \n"RESET);
}
void imprimirVermelho(){
 printf("\n\n\n");
    printf(BRED"\t\t\t____   ____                          .__  .__            \n");
    printf("\t\t\t\\   \\ /   /___________  _____   ____ |  | |  |__   ____  \n");
    printf("\t\t\t \\   Y   // __ \\_  __ \\/     \\_/ __ \\|  | |  |  \\ /  _ \\ \n");
    printf("\t\t\t  \\     /\\  ___/|  | \\/  Y Y  \\  ___/|  |_|   Y  (  <_> )\n");
    printf("\t\t\t   \\___/  \\___  >__|  |__|_|  /\\___  >____/___|  /\\____/ \n");
    printf("\t\t\t              \\/            \\/     \\/          \\/        \n"RESET);
}
void imprimirAzul(){
printf("\n\n\n");
    printf(BBLU"\t\t\t\t   ____      ______    __    __   _____      \n");
    printf("\t\t\t\t  (    )    (____  )   ) )  ( (  (_   _)     \n");
    printf("\t\t\t\t  / /\\ \\        / /   ( (    ) )   | |       \n");
    printf("\t\t\t\t ( (__) )   ___/ /_    ) )  ( (    | |       \n");
    printf("\t\t\t\t  )    (   /__  ___)  ( (    ) )   | |   __  \n");
    printf("\t\t\t\t /  /\\  \\    / /____   ) \\__/ (  __| |___) ) \n");
    printf("\t\t\t\t/__(  )__\\  (_______)  \\______/  \\________/  \n"RESET);
}
void Perdeu(){
Cores c;
desempilharCores(&c);
system("cls");
printf("\n\n\n");
printf(BHRED"\t\t\t\t                                           _                 __ \n");
printf("\t\t\t\t                                          | |             _ / / \n");
printf("\t\t\t\t __   _____   ___ ___   _ __   ___ _ __ __| | ___ _   _  (_) |  \n");
printf("\t\t\t\t \\ \\ / / _ \\ / __/ _ \\ | '_ \\ / _ \\ '__/ _` |/ _ \\ | | |   | |  \n");
printf("\t\t\t\t  \\ V / (_) | (_|  __/ | |_) |  __/ | | (_| |  __/ |_| |  _| |  \n");
printf("\t\t\t\t   \\_/ \\___/ \\___\\___| | .__/ \\___|_|  \\__,_|\\___|\\__,_| (_) |  \n");
printf("\t\t\t\t                       | |                                  \\_\\ \n");
printf("\t\t\t\t                       |_|                                      \n"RESET);
}
void Ganhou(){
Cores c;
desempilharCores(&c);
system("cls");
printf("\n\n\n");
printf(BHGRN"\t\t\t\t                                          _                   __   \n");
printf("\t\t\t\t                                         | |                  \\ \\  \n");
printf("\t\t\t\t __   _____   ___ ___    __ _  __ _ _ __ | |__   ___  _   _  (_) | \n");
printf("\t\t\t\t \\ \\ / / _ \\ / __/ _ \\  / _` |/ _` | '_ \\| '_ \\ / _ \\| | | |   | | \n");
printf("\t\t\t\t  \\ V / (_) | (_|  __/ | (_| | (_| | | | | | | | (_) | |_| |  _| | \n");
printf("\t\t\t\t   \\_/ \\___/ \\___\\___|  \\__, |\\__,_|_| |_|_| |_|\\___/ \\__,_| (_) | \n");
printf("\t\t\t\t                         __/ |                                /_/  \n");
printf("\t\t\t\t                        |___/                                      \n"RESET);
}

void Pontuacao(){
if(pontuacao > max_points)
    max_points = pontuacao;
}

int count = 0;
void imprimirCores(No* no, int quantidade){
    int vezesImprimido = 0;
    if (count == 0) { // verifica se é o primeiro registro
        if (no->cor == "AMARELO") {
            imprimirAmarelo();
            vezesImprimido++;
        } else if (no->cor == "VERDE") {
            imprimirVerde();
            vezesImprimido++;
        } else if (no->cor == "VERMELHO") {
            imprimirVermelho();
            vezesImprimido++;
        } else if (no->cor == "AZUL") {
            imprimirAzul();
            vezesImprimido++;
        }
        count++;
    }
    while (vezesImprimido < quantidade) {
        if (no->cor == "AMARELO") {
            imprimirAmarelo();
        } else if (no->cor == "VERDE") {
            imprimirVerde();
        } else if (no->cor == "VERMELHO") {
            imprimirVermelho();
        } else if (no->cor == "AZUL") {
            imprimirAzul();
        }
        vezesImprimido++;
        if (no->proximo != NULL && vezesImprimido < quantidade) {
            no = no->proximo;
        } else {
            break;
        }
    }
}
void Menu(){

       int op;

       printf("\t\t\t\t         Olá! Escolha uma opção para continuar!");
       printf("\n\n\t\t\t\t\t\t     1 - Começar \n\n\t\t\t\t\t\t    2 - Como Jogar \n\n\t\t\t\t\t\t      3 - Sair\n\n\t\t\t\t\t\t        > ");
       scanf("%d", &op);
       switch(op){

       case 1:
            Jogar();
            break;
        case 2:
            comoJogar();
            break;
        case 3:
            break;
       default:
        Menu();
        break;
       }
}
void empilharCores(Cores *c){


srand(time(NULL));
    int r = rand() % 4;

    for (int i = 0; i < 15; i++){

          r = rand() % 4;
          r+=1;

        if(r == 1)
            r = "AMARELO";
        else if(r == 2)
            r = "VERDE";
        else if(r ==3)
            r = "VERMELHO";
        else if(r==4)
            r = "AZUL";

         if(r != ""){
             No *no = malloc(sizeof(No));
             no->cor = r;
             no->proximo = c->topo;
             c->topo = no;
         }
}
}
void desempilharCores(Cores *c){
No *no = NULL;
    for(int i = 0; i < 15;i++)
    {
        if(c->topo){
        no = c->topo; //o nó recebe oq ta no topo da pilha
        c->topo = no->proximo; //o topo da pilha recebe o endereço que apontava antes
        }
    }
}
int verificaCores(No* no, int qtdItens) {
    int saoIguais = 0;
    No* p = no;
    char corLida[10];
                Pontuacao();

    imprimirNome();
    for(int i = 0; i < qtdItens; i++) {
        if(p == NULL) { // se a lista ligada acabou, retorna 0
            return 0;
        }
        printf("\t\t\t\t           Quais as cores impressas na tela?\n\t\t\t\t\t\t      > ");
        fflush(stdin);
        fgets(corLida, 10, stdin);
        corLida[strcspn(corLida, "\n")] = 0; // remove o \n lido pelo fgets

         for(int j = 0; corLida[j] != '\0'; j++) {
            corLida[j] = toupper(corLida[j]);
         }

        if(strcmp(corLida, p->cor) == 0) {
            saoIguais = 1;
        } else {
            saoIguais = 0;
            break; // se as cores forem diferentes, para o loop
        }

        p = p->proximo; // avança para o próximo nó
    }

    return saoIguais;
}
void comoJogar(){
system("cls");
imprimirNomeSemRecorde();
    int op;
    printf("\n\n\n");
    printf("\t\tGenius é um jogo eletrônico de memória que pode ser jogado por uma ou mais pessoas.\n");
    printf("\t\tApós o inicio do jogo, algumas cores aparecerão na tela, durante 1 segundo, logo\n");
    printf("\t\tdepois, você terá que digitar a cor que foi exibida.\n\t\tCaso erre a sequência, o jogo é reiniciado.\n");
    printf("\t\tÉ necessário que seja enviada uma cor de cada vez, pressionando a tecla 'ENTER' no \n\t\tfinal para realizar a validação.\n");
    printf("\t\tO jogo tem o máximo de 15 partidas, nas quais serão somados 5 pontos a cada acerto.\n");
    printf(BBLK"\t\t\t\t   _                         _                   \n");
    printf("\t\t\t\t  | |__   ___  _ __ ___     (_) ___   __ _  ___  \n");
    printf("\t\t\t\t  | '_ \\ / _ \\| '_ ` _ \\    | |/ _ \\ / _` |/ _ \\ \n");
    printf("\t\t\t\t  | |_) | (_) | | | | | |   | | (_) | (_| | (_) |\n");
    printf("\t\t\t\t  |_.__/ \\___/|_| |_| |_|  _/ |\\___/ \\__, |\\___/ \n");
    printf("\t\t\t\t                          |__/       |___/       \n"RESET);

printf("\n\n\t\tPressione qualquer tecla para voltar ao menu...");
getch();

system("cls");
imprimirNomeSemRecorde();
Menu();
}

void Jogar(){

    Cores c;
    c.topo = NULL;
    c.cor = NULL;

    empilharCores(&c);

    int quantidade = 1;
    int corinserida;
    char textoTeclado[9];
    system("cls");

    for(int i=0; i <= quantidade;i++){
        imprimirCores(c.topo,quantidade);
        delay(1);
        system("cls");

        if(verificaCores(c.topo,quantidade) == 1)
        {
            quantidade++;
            pontuacao+=5;
            system("cls");

            if(quantidade == 15)
                {
                      pontuacao = 0;
                      Ganhou();
                      delay(3);
                      system("cls");
                      imprimirNome();
                      Menu();
                      break;
                }
        }
        else
        {
              pontuacao = 0;
              Perdeu();
              delay(3);
              system("cls");
              imprimirNome();
              Menu();
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    system("cls");

    imprimirNome();
    Menu();

}
