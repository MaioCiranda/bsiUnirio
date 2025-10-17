#define _DEFAULT_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct carta
{
    char numero;
    int valor;
    char naipe[8];
};

struct jogador
{
    char nome[20];
    int soma;
    carta carta_j[11];
    int as;
};

int main ()
{
    srandom(time(NULL));

    carta baralho[52];
    memset(baralho, 0, sizeof(baralho));

    int nj = 0;
    while (nj < 1 || nj > 4)
    {
        printf("Número de jogadores: ");
        scanf(" %d", &nj);
    }
    jogador jogadores[nj];
    memset(jogadores, 0, sizeof(jogadores));
    for (int i = 1; i <= nj; i++)
    {
        printf("Jogador %i: ", i);
        
        if (i == 1) while (getchar() != '\n' && getchar() != EOF);
        fgets(jogadores[i - 1].nome, 20, stdin);
        jogadores[i - 1].nome[strcspn(jogadores[i - 1].nome, "\n")] = '\0';
    }

    // Initialize deck
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            unsigned int r = random() % 52;
            while (isalpha(baralho[r].naipe[0]))
            {
                r = random() % 52;
            }

            if (i == 0)
            {
                strcpy(baralho[r].naipe, "ouros");
            }
            else if (i == 1)
            {
                strcpy(baralho[r].naipe, "espadas");
            }
            else if (i == 2)
            {
                strcpy(baralho[r].naipe, "copas");
            }
            else if (i == 3)
            {
                strcpy(baralho[r].naipe, "paus");
            }
            if (j >= 1 && j <= 10)
            {
                baralho[r].numero = '0' + j;
                baralho[r].valor = j;
            }
            else if (j == 11)
            {
                baralho[r].numero = 'J';
                baralho[r].valor = 10;
            }
            else if (j == 12)
            {
                baralho[r].numero = 'Q';
                baralho[r].valor = 10;
            }
            else if (j == 13)
            {
                baralho[r].numero = 'K';
                baralho[r].valor = 10;
            }
            else if (j == 1)
            {
                baralho[r].numero = 'A';
                baralho[r].valor = 1;
            }
        }
    }

    // Shuffle players
    for (int i = 0; i < 50; i++)
    {
        unsigned int r_um = random() % nj;
        unsigned int r_dois = random() % nj;
        char temp[20];
        strcpy(temp, jogadores[r_um].nome);
        strcpy(jogadores[r_um].nome, jogadores[r_dois].nome);
        strcpy(jogadores[r_dois].nome, temp);
    }

    jogador fora_do_jogo[4];
    int saiu = 0;

    int carta_da_vez = 0;
    while (nj > 0) // Continue until all players are out
    {
        for (int j = 0; j < nj; j++)
        {
            printf("\n%s: ", jogadores[j].nome);

            // Display player's cards
            for (int k = 0; k <= jogadores[j].soma / 10; k++)
            {
                printf("%c de %s | ", jogadores[j].carta_j[k].numero,
                       jogadores[j].carta_j[k].naipe);
            }

            // Player choice
            if (jogadores[j].soma < 21)
            {
                printf("\nComprar - C Parar - P ");
                char c = getchar();
                getchar(); // Flush newline

                if (toupper(c) == 'C')
                {
                    jogadores[j].carta_j[jogadores[j].soma / 10] = baralho[carta_da_vez];
                    jogadores[j].soma += baralho[carta_da_vez].valor;
                    if (baralho[carta_da_vez].numero == 'A')
                        jogadores[j].as++;
                    carta_da_vez++;
                }
                else if (toupper(c) == 'P')
                {
                    fora_do_jogo[saiu] = jogadores[j];
                    saiu++;
                    for (int k = j; k < nj - 1; k++)
                    {
                        jogadores[k] = jogadores[k + 1];
                    }
                    nj--;
                    j--;
                }
            }

            // Check for bust
            if (jogadores[j].soma > 21)
            {
                printf("\n%s estourou com %d pontos!\n", jogadores[j].nome, jogadores[j].soma);
                fora_do_jogo[saiu] = jogadores[j];
                saiu++;
                for (int k = j; k < nj - 1; k++)
                {
                    jogadores[k] = jogadores[k + 1];
                }
                nj--;
                j--;
            }
        }
    }

    // Display results
    printf("\n--- Resultado ---\n");
    for (int i = 0; i < saiu; i++)
    {
        printf("%s: %d pontos\n", fora_do_jogo[i].nome, fora_do_jogo[i].soma);
    }

    return 0;
}