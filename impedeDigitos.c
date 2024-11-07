/*Demonstra o uso do CONTINUE*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main () {
    char ch;
    while ((ch = getche()) != 'x')
    {
        if (ch >= '0' && ch <= '9')
        {
            continue;
            printf("passou pelo continue");
        }
        printf("digitou %c\n", ch);
    }
    printf("\n");
    system("PAUSE");
    return 0;
    
}
