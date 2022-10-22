#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vogal(char letra);

int saoLetrasIguais(char primeiraLetra, char segundaLetra);

int main(void)
{
    int qtdCasosTeste = 0;
    char primeiraPalavra[20], segundaPalavra[20];

    scanf("%d", &qtdCasosTeste);

    if (qtdCasosTeste <= 20)
        for (int primContador = 0; primContador < qtdCasosTeste; primContador++)
        {
            scanf("%s", primeiraPalavra);
            scanf("%s", segundaPalavra);
            int possuemMesmoTamanho = strlen(primeiraPalavra) == strlen(segundaPalavra);
            if (possuemMesmoTamanho)
            {
                int podemSerIguais = 0;
                for (int segContador = 0; segContador < strlen(primeiraPalavra); segContador++)
                {
                    int saoIguais = saoLetrasIguais(primeiraPalavra[segContador], segundaPalavra[segContador]);
                    if (saoIguais) 
                        podemSerIguais = 1;
                    else if (vogal(primeiraPalavra[segContador]) && vogal(segundaPalavra[segContador]))
                        podemSerIguais = 1;
                    else
                    {
                        podemSerIguais = 0;
                        printf("No\n");
                        break;
                    }
                }
                if (podemSerIguais)
                    printf("Yes\n");
            }
            else
                printf("No\n");
        }
}

int vogal(char letra)
{
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        return 1;
    return 0;
}

int saoLetrasIguais(char primeiraLetra, char segundaLetra)
{
    if (primeiraLetra == segundaLetra)
        return 1;
    return 0;
}