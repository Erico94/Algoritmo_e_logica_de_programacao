#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main () {
    int numeroDeZeros= 0;
    char caracteres;

    printf("Digite algo:\n");
    while ((caracteres = getche ()) != '\r')
    {
        if (caracteres == '0')
        {
            numeroDeZeros ++;
        }
        
    }
    if (numeroDeZeros > 0)
    {
    printf ("\nTotal de zeros: %d.\n", numeroDeZeros);
    }
    else printf ("\nVoce nao digitou nenhum zero\n.");
    
    system("PAUSE");
    
    return 0;
}