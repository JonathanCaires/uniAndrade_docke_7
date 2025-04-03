#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_PLAYERS 3 // Definir número de jogadores
#define INVENTARIO_TAM 5 // Número de itens no inventário


// int main(int argc, char const *argv[])
// {
//     for(int i=0; i < argc; i++){
//         printf("Arg[%i] %s\n", i, argv[i]);
//     }
//     return 0;
// }
//funções que executam funções 
// float intToFloat(int n){
//     return n;
// }

// void format(){
//     printf("TT__________________________________________________TT\n");
//     printf("=========É muito cremoso formatar a metade===========\n");
//     printf("||                                                  ||\n");
//     printf("||                                                  ||\n");
// }

// void formatfinal(){
//     printf("\n||                                                  ||\n");
//     printf("||                                                  ||\n");
//     printf("======================================================\n");
// }

// void halfConvert(int n){
//     float half = intToFloat(n)* 0.5;
//     printf("||                 metade: %.2f                     ||", half);
// }

typedef struct {
    char nome[50]; // Defina um tamanho para o array
    int nivel;
    float forca;
    bool tem_arma;
    char inventario[INVENTARIO_TAM][30]; // Inventário com até 5 itens
} Player;

void imprimirPlayer(Player *p) {
    printf("=======================================\n");
    printf("|          INVENTÁRIO DO JOGADOR       |\n");
    printf("=======================================\n");
    printf("| Nome: %-30s |\n", p->nome);
    printf("| Nível: %-29d |\n", p->nivel);
    printf("| Força: %-29.2f |\n", p->forca);
    printf("| Tem arma: %-25s |\n", p->tem_arma ? "Sim" : "Não");
    printf("---------------------------------------\n");
    printf("| INVENTÁRIO:                          |");
    for (int i = 0; i < INVENTARIO_TAM; i++) {
        if (p->inventario[i][0] != '\0') { // Verifica se há item no slot
            printf("\n| [%d] %-30s |", i + 1, p->inventario[i]);
        } else {
            printf("\n| [%d] %-30s |", i + 1, "[Vazio]");
        }
    }
    printf("\n=======================================\n");
}

int main() {
    Player jogadores[NUM_PLAYERS] = {
        {"Alice", 10, 75.5, true, {"Espada", "Poção", "Escudo", "", ""}},
        {"Bob", 8, 60.3, false, {"Arco", "Flechas", "Poção", "Elmo", ""}},
        {"Charlie", 12, 90.0, true, {"Machado", "Cota de malha", "Poção", "Botas", "Amuleto"}}
    };

    for (int i = 0; i < NUM_PLAYERS; i++) {
        imprimirPlayer(&jogadores[i]);
        printf("\n");
    }
    return 0;
}