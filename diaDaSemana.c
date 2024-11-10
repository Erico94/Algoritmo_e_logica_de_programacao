#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main () {

    int dia=0, mes=0, ano=0, diaDaSemana;
    const char ESC = 27;

    do
    {
        printf("\nDigite a data no formato DD MM AAAA\n");
        scanf("%d%d%d", &dia, &mes, &ano);

        diaDaSemana = ano + dia + 3*(mes -1) -1;
        if (mes<3)
        {
            ano--;
        }else
        {
            diaDaSemana -= (int)(0.4 * mes +2.3);
        }
        diaDaSemana += (int) (ano/4) - (int) ((ano / 100 + 1) * 0.75 );
        diaDaSemana %= 7;

        switch (diaDaSemana)
        {
        case 0:
            printf("Domingo");
            break;
        case 1:
            printf("segunda");
            break;
        case 2:
            printf("terca");
            break;
        case 3:
            printf("quarta");
            break;
        case 4:
            printf("quinta");
            break;
        case 5:
            printf("sexta");
            break;
        case 6:
            printf("sabado");
            break;
        }
    printf("\nPressione ESC para terminar ou ENTER para recomecar.\n");
        
        
        
    } while (getch()!= ESC);

    system("PAUSE");
    
    return 0;
}