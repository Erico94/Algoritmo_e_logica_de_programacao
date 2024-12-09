#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char marca[25];
    int metrosPorRolo;
    int quantDeRolos;
    float precoDoPacote;
    float precoPorMetro;
    float precoPorRolo;
} Rolo;

void calcularValorPorMetro(int *metrosPorRolo, int *quantDeRolos, float *precoDoPacote, float *precoPorMetro, float *precoPorRolo);

int main()
{
    Rolo rolo1;
    printf("\nInsira as informações solicitadas sobre o primeiro pacote:");
    printf("\nMarca:");
    scanf(" %[^\n]s", rolo1.marca);
    printf("\nQuantidade de rolos:");
    scanf("%d", &rolo1.quantDeRolos);
    printf("\nMetros por rolo:");
    scanf("%d", &rolo1.metrosPorRolo);
    printf("\nPreco do pacote:");
    scanf("%f", &rolo1.precoDoPacote);
    calcularValorPorMetro(&rolo1.metrosPorRolo, &rolo1.quantDeRolos, &rolo1.precoDoPacote, &rolo1.precoPorMetro, &rolo1.precoPorRolo);
    printf("\nMarca %s", rolo1.marca);
    printf("\nPreco por metro: %.2f.", rolo1.precoPorMetro);
    printf("\nPreco por cada rolo de %d metros: %.2f. \n", rolo1.metrosPorRolo, rolo1.precoPorRolo);
    system("pause");
}
void calcularValorPorMetro(int *metrosPorRolo, int *quantDeRolos, float *precoDoPacote, float *precoPorMetro, float *precoPorRolo)
{
    float metragemTotal = *metrosPorRolo * *quantDeRolos;
    *precoPorMetro = *precoDoPacote / metragemTotal;
    *precoPorRolo = *precoPorMetro * *metrosPorRolo;
    return;
}
