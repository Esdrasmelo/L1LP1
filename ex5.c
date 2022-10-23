#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int areAllNumbersEqual(char cpf[12]);

int shouldStop(char cpf[12]);

int getSumValueOfNineDigits(char cpf[12]);

int calculateFirstVerifyingDigitValue(int sumedValue);

int getSumValueOfTenDigits(char cpf[12]);

int calculateSecondVerifyingDigitValue(int sumedValue);

int areDigitsEquals(int calculedFirstDigit, int calculedSecondDigit, int firstDigit, int secondDigit);

int main(void)
{
    char cpf[12];

    scanf(" %c%c%c.%c%c%c.%c%c%c-%c%c", &cpf[0], &cpf[1], &cpf[2], &cpf[3], &cpf[4], &cpf[5], &cpf[6], &cpf[7], &cpf[8], &cpf[9], &cpf[10]);

    while (!shouldStop(cpf))
    {
        if (areAllNumbersEqual(cpf))
            printf("inválido\n");
        else
        {
            int nineDigitsSumed = getSumValueOfNineDigits(cpf);
            int tenDigitsSumed = getSumValueOfTenDigits(cpf);
            int calculatedFirstDigit = calculateFirstVerifyingDigitValue(nineDigitsSumed);
            int calculatedSecondDigit = calculateSecondVerifyingDigitValue(tenDigitsSumed);
            int firstDigit = cpf[strlen(cpf) - 2] - '0';
            int secondDigit = cpf[strlen(cpf) - 1] - '0';
            int areAllDigitsEquals = areDigitsEquals(calculatedFirstDigit, calculatedSecondDigit, firstDigit, secondDigit);

            if (areAllDigitsEquals)
                printf("válido\n");
            else
                printf("inválido - esperado: %d%d, encontrado: %d%d\n", calculatedFirstDigit, calculatedSecondDigit, firstDigit, secondDigit);
        }
        scanf(" %c%c%c.%c%c%c.%c%c%c-%c%c", &cpf[0], &cpf[1], &cpf[2], &cpf[3], &cpf[4], &cpf[5], &cpf[6], &cpf[7], &cpf[8], &cpf[9], &cpf[10]);
    }
}

int shouldStop(char cpf[12])
{
    int quantityOfZeros = 0;
    for (int index = 0; index < strlen(cpf) && cpf[index] != '\0'; index++)
    {
        if (cpf[index] == '0')
            quantityOfZeros += 1;
    }
    if (quantityOfZeros != strlen(cpf))
        return 0;
    return 1;
}

int areAllNumbersEqual(char cpf[12])
{
    int quantityEqualsNumbers = 0;
    for (int index = 0; index < strlen(cpf) && cpf[index] != '\0'; index++)
    {
        int isSpecialChar = cpf[index] == '.' || cpf[index] == '-';
        if (!isSpecialChar && cpf[index] == cpf[index + 1])
            quantityEqualsNumbers += 1;
    }
    if (quantityEqualsNumbers == strlen(cpf) - 1)
        return 1;
    return 0;
}

int getSumValueOfNineDigits(char cpf[12])
{
    int finalValue = 0;

    for (int index = 0; index < 9 && cpf[index] != '\0'; index++)
        finalValue += (index + 1) * (cpf[index] - '0');

    return finalValue;
}

int calculateFirstVerifyingDigitValue(int sumedValue)
{
    double rest = sumedValue % 11;

    if (rest == 10)
        return 0;
    return (int)rest;
}

int getSumValueOfTenDigits(char cpf[12])
{
    int finalValue = 0;
    char cpfIndex = 0;

    for (int index = 11; index > 1 && cpf[cpfIndex] != '\0'; index -= 1)
    {
        finalValue += index * cpf[cpfIndex] - '0';
        cpfIndex += 1;
    }

    return finalValue;
}

int calculateSecondVerifyingDigitValue(int sumedValue)
{
    int multipliedValue = sumedValue * 10;
    double rest = multipliedValue % 11;

    if (rest == 10)
        return 0;
    return (int)rest;
}

int areDigitsEquals(int calculedFirstDigit, int calculedSecondDigit, int firstDigit, int secondDigit)
{
    int areFirstDigitsEquals = calculedFirstDigit == firstDigit;
    int areSecondDigitsEquals = calculedSecondDigit == secondDigit;

    if (areFirstDigitsEquals && areSecondDigitsEquals)
        return 1;
    return 0;
}