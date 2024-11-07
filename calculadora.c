#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ativa = 0;

    printf("\nDigite 1 para ligar a calculadora ou 0 para manter desligada.\n");
    scanf("%d", &ativa);
    while (ativa == 1.0)
    {
        float segundoNumero = 0, primeiroNumero = 0;
        char operador;
        float total = 0;

        printf("\nDigite um numero, o operador e o segundo numero, sem espacos entre eles.\n");
        printf("Ex: 2+7\n");
        scanf("%f%c%f", &primeiroNumero, &operador, &segundoNumero);

        if(primeiroNumero==0 || segundoNumero==0) { 
            printf("Zero detectado, programa sendo encerrado.");
            break; /*Encerra o programa caso algum zero seja detectado*/
            } 
        if (operador == '+')
        {
            total = primeiroNumero + segundoNumero;
            printf("\nVoce digitou %.2f %c %.2f e o resultado eh: %.2f\n", primeiroNumero, operador,
             segundoNumero, total);
        }
        else if (operador == '-')
        {
            total = primeiroNumero - segundoNumero;
            printf("\nVoce digitou %.2f %c %.2f e o resultado eh: %.2f\n", primeiroNumero, operador,
             segundoNumero, total);
        }
        else if (operador == '/')
        {
            total = primeiroNumero / segundoNumero;
            printf("\nVoce digitou %.2f %c %.2f e o resultado eh: %.2f\n", primeiroNumero, operador,
             segundoNumero, total);
        }
        else if (operador == '*')
        {
            total = primeiroNumero * segundoNumero;
            printf("\nVoce digitou %.2f %c %.2f e o resultado eh: %.2f\n", primeiroNumero, operador,
             segundoNumero, total);
        }
        else
            printf("\nOperador desconhecido.\n");

        printf("Digite 1 para ligar a calculadora ou 0 para manter desligada.\n");
        scanf("%d", &ativa);
    }
    return 0;
}