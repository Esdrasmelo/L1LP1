#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int areAllNumbersEqual(char cpf[12]);

int shouldStop(char cpf[12]);

int getSumValueOfNineDigits(char cpf[12]);

int calculateFirstVerifyingDigitValue(int sumedValue);

int getSumValueOfTenDigits(char cpf[12]);

int calculateSecondVerifyingDigitValue(int sumedValue);

int areVerifyingDigitsEquals(int calculedFirstDigit, int calculedSecondDigit, int firstDigit, int secondDigit);

int main(void)
{
    char cpf[15];
    char secondCpfArray[12];
    char thirdCpfArray[13];
    int auxCounter = 0;
    int amountOfDots = 0;
    int amountOfMinusSignal = 0;

    scanf(" %s", cpf);

    for (int index = 0; index < 15; index++)
    {
        if (cpf[index] != '.' && cpf[index] != '-')
        {
            secondCpfArray[auxCounter] = cpf[index];
            auxCounter++;
        }
    }

    if (strlen(secondCpfArray) < 11)
    {
        int neededZeros = 11 - strlen(secondCpfArray);

        for (int index = 0; index < neededZeros; index++)
            thirdCpfArray[index] = '0';
        for (int index = neededZeros; index < strlen(secondCpfArray) + neededZeros; index++)
        {
            thirdCpfArray[index] = secondCpfArray[index - neededZeros];
        }
    }

    while (!shouldStop(secondCpfArray))
    {
        int areNumbersEquals = strlen(secondCpfArray) < 11 ? areAllNumbersEqual(thirdCpfArray) : areAllNumbersEqual(secondCpfArray);
        if (areNumbersEquals)
            printf("inválido\n");
        else
        {
            int nineDigitsSumed = strlen(secondCpfArray) < 11 ? getSumValueOfNineDigits(thirdCpfArray) : getSumValueOfNineDigits(secondCpfArray);
            int tenDigitsSumed = strlen(secondCpfArray) < 11 ? getSumValueOfTenDigits(thirdCpfArray) : getSumValueOfTenDigits(secondCpfArray);
            int calculatedFirstDigit = calculateFirstVerifyingDigitValue(nineDigitsSumed);
            int calculatedSecondDigit = calculateSecondVerifyingDigitValue(tenDigitsSumed);
            int firstDigit = strlen(secondCpfArray) < 11 ? thirdCpfArray[strlen(thirdCpfArray) - 2] - '0' : secondCpfArray[strlen(secondCpfArray) - 2] - '0';
            int secondDigit = strlen(secondCpfArray) < 11 ? thirdCpfArray[strlen(thirdCpfArray) - 1] - '0' : secondCpfArray[strlen(secondCpfArray) - 1] - '0';
            int areAllDigitsEquals = areVerifyingDigitsEquals(calculatedFirstDigit, calculatedSecondDigit, firstDigit, secondDigit);

            if (areAllDigitsEquals)
                printf("válido\n");
            else
                printf("inválido - esperado: %d%d, encontrado: %d%d\n", calculatedFirstDigit, calculatedSecondDigit, firstDigit, secondDigit);
        }
        
        scanf(" %s", cpf);

        auxCounter = 0;
        for (int index = 0; index < 15; index++)
        {
            if (cpf[index] != '.' && cpf[index] != '-')
            {
                secondCpfArray[auxCounter] = cpf[index];
                auxCounter++;
            }
        }
    }
}

int shouldStop(char cpf[12])
{
    int quantityOfZeros = 0;
    for (int index = 0; index < strlen(cpf) && cpf[index] != '\0'; index++)
    {
        if (cpf[index] == '0')
        {
            quantityOfZeros += 1;
        }
    }
    if (quantityOfZeros == 11)
        return 1;
    return 0;
}

int areAllNumbersEqual(char cpf[12])
{
    int quantityEqualsNumbers = 0;
    for (int index = 0; index < strlen(cpf) && cpf[index] != '\0'; index++)
    {
        if (cpf[index] == cpf[index + 1])
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

int areVerifyingDigitsEquals(int calculedFirstDigit, int calculedSecondDigit, int firstDigit, int secondDigit)
{
    int areFirstDigitsEquals = calculedFirstDigit == firstDigit;
    int areSecondDigitsEquals = calculedSecondDigit == secondDigit;

    if (areFirstDigitsEquals && areSecondDigitsEquals)
        return 1;
    return 0;
}