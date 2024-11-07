#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int numeroCaracteres = -1;
    int numeroPalavras = 1;
    char ch;

    printf("Digite uma frase: \n");
    while ((ch = getche()) != '\r')
    {
        numeroCaracteres ++;
        if (ch == ' ')
        {
            numeroPalavras ++;
        }
        
    }
    printf("\nNumero de caracteres = %d \n", numeroCaracteres);
    printf("Numero de palavras = %d \n", numeroPalavras);
    system("PAUSE");
    return 0;
}