#include <stdio.h>
int main()
{
    float nota1, nota2, nota3, media;
    printf("Entre com a primeira nota:\n");
    scanf("%f", &nota1);
    
    printf("Entre com a segunda nota:\n");
    scanf("%f", &nota2);
    
    printf("Entre com a terceira nota:\n");
    scanf("%f", &nota3);
    media = (nota1 + nota2 + nota3)/3;
    printf("A media e: %.2f. \n", media);
    if (media <5){
        printf("Aluno reprovado.\n");
    }else{
        if (media<7)
        {
            printf("Aluno em recuperacao.\n");
        }else{
            printf("Aluno aprovado.\n");
        }
    }
    
    return 0;

}