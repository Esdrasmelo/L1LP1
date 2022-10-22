#include <stdio.h>

int PecaMes[3][3], GranaPeca[3][2], GranaMes[3][2], primContador = 0, segContador = 0, custoJan = 0, lucroJan = 0, custoFev = 0, lucroFev = 0, custoMarc = 0, lucroMarc = 0;

int calcularCustoJan();

int calcularLucroJan();

int calcularCustoFev();

int calcularLucroFev();

int calcularCustoMarc();

int calcularLucroMarc();

int main(void)
{
    for (primContador = 0; primContador < 3; primContador++)
        for (segContador = 0; segContador < 3; segContador++)
            scanf("%d", &PecaMes[primContador][segContador]);

    for (primContador = 0; primContador < 3; primContador++)
        for (segContador = 0; segContador < 2; segContador++)
            scanf("%d", &GranaPeca[primContador][segContador]);

    for (primContador = 0; primContador < 3; primContador++)
    {
        if (primContador == 0)
            for (segContador = 0; segContador < 3; segContador++)
            {
                GranaMes[0][0] = calcularCustoJan();
                GranaMes[0][1] = calcularLucroJan();
            }

        else if (primContador == 1)
            for (segContador = 0; segContador < 3; segContador++)
            {
                GranaMes[1][0] = calcularCustoFev();
                GranaMes[1][1] = calcularLucroFev();
            }
        else
            for (segContador = 0; segContador < 3; segContador++)
            {
                GranaMes[2][0] = calcularCustoMarc();
                GranaMes[2][1] = calcularLucroMarc();
            }
    }

    for (primContador = 0; primContador < 3; primContador++)
        for (segContador = 0; segContador < 2; segContador++)
        {
            if (primContador == 0 && segContador == 0)
            {
                printf("\n\nJANEIRO:\n");
                printf("\tCUSTO: %d\n", GranaMes[primContador][segContador]);
            }
            else if (primContador == 0 && segContador == 1)
                printf("\tLUCRO: %d\n", lucroJan);
            else if (primContador == 1 && segContador == 0)
            {
                printf("FEVEREIRO:\n");
                printf("\tCUSTO: %d\n", GranaMes[primContador][segContador]);
            }
            else if (primContador == 1 && segContador == 1)
                printf("\tLUCRO: %d\n", GranaMes[primContador][segContador]);
            else if (primContador == 2 && segContador == 0)
            {
                printf("MARÇO:\n");
                printf("\tCUSTO: %d\n", GranaMes[primContador][segContador]);
            }
            else
                printf("\tLUCRO: %d\n", GranaMes[primContador][segContador]);
        }
}

int calcularCustoJan()
{
    int linha = 0, coluna = 0;

    if (segContador == 0)
        for (linha = 0; linha < 1; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoJan += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else if (segContador == 1)
        for (linha = 1; linha < 2; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoJan += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else
        for (linha = 2; linha < 3; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoJan += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
}

int calcularLucroJan()
{
    int linha = 0, coluna = 0;

    if (segContador == 0)
        for (linha = 0; linha < 1; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroJan += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else if (segContador == 1)
        for (linha = 1; linha < 2; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroJan += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else
        for (linha = 2; linha < 3; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroJan += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
}

int calcularCustoFev()
{
    int linha = 0, coluna = 0;

    if (segContador == 0)
        for (linha = 0; linha < 1; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoFev += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else if (segContador == 1)
        for (linha = 1; linha < 2; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoFev += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else
        for (linha = 2; linha < 3; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoFev += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
}

int calcularLucroFev()
{
    int linha = 0, coluna = 0;

    if (segContador == 0)
        for (linha = 0; linha < 1; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroFev += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else if (segContador == 1)
        for (linha = 1; linha < 2; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroFev += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else
        for (linha = 2; linha < 3; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroFev += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
}

int calcularCustoMarc()
{
    int linha = 0, coluna = 0;

    if (segContador == 0)
        for (linha = 0; linha < 1; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoMarc += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else if (segContador == 1)
        for (linha = 1; linha < 2; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoMarc += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else
        for (linha = 2; linha < 3; linha++)
            for (coluna = 0; coluna < 1; coluna++)
                custoMarc += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
}

int calcularLucroMarc()
{
    int linha = 0, coluna = 0;

    if (segContador == 0)
        for (linha = 0; linha < 1; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroMarc += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else if (segContador == 1)
        for (linha = 1; linha < 2; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroMarc += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
    else
        for (linha = 2; linha < 3; linha++)
            for (coluna = 1; coluna < 2; coluna++)
                lucroMarc += PecaMes[primContador][segContador] * GranaPeca[linha][coluna];
}