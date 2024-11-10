# include <stdio.h>
# include <stdlib.h>

int main () {
    int opcaoEscolhida = 0;

    printf("\nInsira o numero correspondente a opcao desejada:\n");
    printf("1 - Conta corrente.\n");
    printf("2 - Conta poupanca.\n");
    printf("3 - Conta PJ.\n");

    scanf("%d", &opcaoEscolhida);
    switch (opcaoEscolhida)
    {
    case 1:
        printf("\nVoce selecionou opcao 1 - conta corrente.\n");
        break;
    
    case 2:
        printf("\nVoce selecionou opcao 2 - conta poupanca.\n");
        break;
        
    case 3:
        printf("\nVoce selecionou opcao 3 - conta PJ.\n");
        break;
    default:
        printf("\nOpcao invalida, encerrando programa.\n");
        break;
    }

    return 0;
}