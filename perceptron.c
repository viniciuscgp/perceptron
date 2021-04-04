/*
/// IA - Treinamento de Perceptron
/// Author : Vinicius César
/// Data   : 4/4/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//prototipos
void traco();
void limpa();

int main(int argc, char const *argv[])
{
    // As amostras-----------------------------------
    int x[] = {
        1, 1, 9, 6, 9, 5, 8,
        1, 2, 9, 4, 2, 3, 4,
        0, 3, 4, 2, 1, 2, 1,
        1, 2, 9, 7, 2, 1, 1,
        0, 1, 2, 4, 1, 2, 3,
        0, 5, 6, 2, 1, 3, 1,
        1, 3, 4, 2, 1, 1, 2};

    // Os Pesos inicializados com Zero
    double pesos[7] = {1, 0.9, 0.8, 0.7, 0.6, 0.5, 0.4};
    int objetivos[7] = {1, 1, -1, 1, -1, -1, 1};
    double deltas[49];

    double bias = -1;
    double apren = 0.05; // taxa de aprendizado

    limpa();
    puts("Treinamento de Perceptron");
    traco();
    printf(" I\tx1 |\tx2 |\tx3 |\tx4 |\tx5 |\tx6 |\tx7 |\td     |\tf  |\to  |\terr |\n");
    traco();
    for (int e = 1; e < 10; e++) // Epoca
    {
        printf("| Epoca %d | \n", e);
        traco();

        for (int i = 0; i < 7; i++) // Amostra
        {
            printf(" %d", i);
            double d = 0;
            // Entradas
            for (int j = 0; j < 7; j++)
            {
                d = d + (x[j + (i * 7)] * pesos[j]);
                printf("\t%2d |", x[j + (i * 7)]);
            }
            // aplica o bias----------------------------------------
            d += bias;
            // Funcao de ativacao-----------------------------------
            int f = d >= 0 ? 1 : -1;
            int e = objetivos[i] - f;

            printf("\t%05.2f |", d);
            printf("\t%2d |", f);
            printf("\t%2d |", objetivos[i]);
            printf("\t%2d  |", e);
            printf("\n");
            // Calcula deltas---------------------------------------
            for (int j = 0; j < 7; j++)
            {
                d = d + (x[j + (i * 7)] * pesos[j]);
                deltas[j + (i * 7)] = x[j + (i * 7)] * e * apren;
            }
        } // Amostra

        // Recalcula pesos
        for (int j = 0; j < 7; j++)
        {
            double soma = 0;
            for (int i = 0; i < 7; i++)
            {
                soma += deltas[j + (i * 7)];
            }
            pesos[j] = pesos[j] + (soma / 7);
        }
        traco();
        printf("\n");
    } // Epoca
    return 0;
}
void traco()
{
    for (int i = 0; i < 93; i++)
    {
        printf("-");
    }
    printf("\n");
}

void limpa()
{
    const char *s = strlwr(getenv("OS"));
    if (strncmp(s, "win", 3) == 0)
        system("cls");
    else
        system("clear");
}