#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

struct Produto
{
    char nome[21];
    char descricao[51];
    int quantidade, codigo;
    char ativo[4];
};
int codigoProduto = 0;
int quantidadeAtualEstoque = 1;
struct Produto estoqueProdutos[51];

void seedEstoque()
{
    struct Produto p1 = {"Caneta", "Caneta esferografica azul", 150, 1, ""};
    struct Produto p2 = {"Caderno", "Caderno universitario 100 folhas", 80, 2, ""};
    struct Produto p3 = {"Lapis", "Lapis grafite HB", 200, 3, ""};
    struct Produto p4 = {"Borracha", "Borracha branca", 120, 4, ""};
    struct Produto p5 = {"Regua", "Regua de 30 cm", 60, 5, ""};

    // Usando strcpy para atribuir "Sim" ao campo 'ativo' de cada produto
    strcpy(p1.ativo, "Sim");
    strcpy(p2.ativo, "Sim");
    strcpy(p3.ativo, "Sim");
    strcpy(p4.ativo, "Sim");
    strcpy(p5.ativo, "Sim");

    codigoProduto = 6;

    estoqueProdutos[quantidadeAtualEstoque++] = p1;
    estoqueProdutos[quantidadeAtualEstoque++] = p2;
    estoqueProdutos[quantidadeAtualEstoque++] = p3;
    estoqueProdutos[quantidadeAtualEstoque++] = p4;
    estoqueProdutos[quantidadeAtualEstoque++] = p5;
}
/* Embora seja possível buscar o produto pelo seu código, a linguagem C não possui uma função específica para
exclusão de elementos em arrays. Dessa forma, a remoção de um item do array estoqueProdutos precisa ser feita manualmente. 
Cada vez que um elemento é removido, o array é reorganizado, o que causa a realocação dos elementos e a atualização dos índices.
Assim, o código de cada produto acaba não sendo fixo. Para resolver isso momentâneamente criei uma variável chamada "ativo", onde o produto
pode ser ativado ou desativado e, com isso evitar a reorganização do array.*/
void desativarProdutoPorCodigo()
{
    int codigo;
    printf("\nDigite o codigo do produto a ser desativado:");
    scanf("%d", &codigo);
    for (int i = 0; i < quantidadeAtualEstoque; i++)
    {
        if (codigo == estoqueProdutos[i].codigo)
        {
            strcpy(estoqueProdutos[i].ativo, "Nao");
            printf("Produto desativado.\n");
            return;
        }
    }
    printf("Codigo nao encontrado.\n");
    return;
}

void ativarProdutoPorCodigo()
{
    int codigo;
    printf("\nDigite o codigo do produto a ser ativado:");
    scanf("%d", &codigo);
    for (int i = 0; i < quantidadeAtualEstoque; i++)
    {
        if (codigo == estoqueProdutos[i].codigo)
        {
            strcpy(estoqueProdutos[i].ativo, "Sim");
            printf("Produto ativado.\n");
            return;
        }
    }
    printf("Codigo nao encontrado.\n");
    return;
}


void adicionarProduto()
{
    /*Verifica se ainda há espaço disponível no estoque*/
    if (quantidadeAtualEstoque >= 50)
    {
        printf("Quantidade maxima de estoque atingida.");
        return;
    }
    struct Produto novoProduto;

    /*Inserção dos dados*/
    printf("\n******************************\n");
    printf("ADICIONAR PRODUTO.\n");
    printf("Nome do produto:\n");
    scanf("%s", novoProduto.nome);
    printf("Descricao:\n");
    scanf(" %[^\n]s", novoProduto.descricao);
    printf("Quantidade:\n");
    scanf("%d", &novoProduto.quantidade);
    int ativo;
    printf("Iniciar produto ativado? \n1 para Sim.\n2 para nao.\n");
    scanf("%d", &ativo);
    if (ativo == 1)
    {
        strcpy(novoProduto.ativo, "Sim");
    }
    else
    {
        strcpy(novoProduto.ativo, "Nao");
    }

    novoProduto.codigo = codigoProduto;

    /*Confirmação do salvamento das informações ao usuário.*/
    printf("\n\n******************************\n");
    printf("Nome do produto: %s.\n", novoProduto.nome);
    printf("Descricao: %s.\n", novoProduto.descricao);
    printf("Quantidade: %d.\n", novoProduto.quantidade);
    printf("Codigo: %d.\n", novoProduto.codigo);
    printf("Ativo: %s.\n", novoProduto.ativo);
    printf("Salvo com sucesso\n");
    printf("******************************\n");

    /*Adição do produto ao estoque*/
    estoqueProdutos[quantidadeAtualEstoque] = novoProduto;

    /*Incremento das variáveis: código e quantidade atual no estoque*/
    quantidadeAtualEstoque++;
    codigoProduto++;
    return;
}

void listarTodosOsProdutos()
{
    for (int i = 1; i < quantidadeAtualEstoque; i++)
    {
        printf("\n*****************************\n");
        printf("Nome: %s\n", estoqueProdutos[i].nome);
        printf("Descricao: %s\n", estoqueProdutos[i].descricao);
        printf("Quantidade: %d\n", estoqueProdutos[i].quantidade);
        printf("Codigo: %d\n", estoqueProdutos[i].codigo);
        printf("Ativo: %s\n", estoqueProdutos[i].ativo);
        printf("\n*****************************\n");
    }
    return;
}

void buscaPorId()
{
    int id;

    printf("Digite o codigo identificador do produto:");
    scanf("%d", &id);
    for (int i = 1; i < quantidadeAtualEstoque; i++)
    {
        if (estoqueProdutos[i].codigo == id)
        {
            printf("\n*****************************\n");
            printf("Nome: %s\n", estoqueProdutos[i].nome);
            printf("Descricao: %s\n", estoqueProdutos[i].descricao);
            printf("Quantidade: %d\n", estoqueProdutos[i].quantidade);
            printf("Codigo: %d\n", estoqueProdutos[i].codigo);
            printf("Ativo: %s\n", estoqueProdutos[i].ativo);
            printf("\n*****************************\n");
            break;
        }
    }
    return;
}

int main()
{
    seedEstoque();
    int opcaoSelecionada;
    printf("\n\n**Seja bem vindo ao SysToque, seu sistema de gerenciamento de estoques.**\n");

    do
    {
        printf("Digite o numero referente a opcao desejada:\n");
        printf("1 - Adicionar produto.\n");
        printf("2 - Localizar produto.\n");
        printf("3 - Listar todos os produtos.\n");
        printf("4 - Desativar produto.\n");
        printf("5 - SAIR\n");

        scanf("%d", &opcaoSelecionada);

        switch (opcaoSelecionada)
        {
        case 1:
            adicionarProduto();
            break;
        case 2:
            buscaPorId();
            break;
        case 3:
            listarTodosOsProdutos();
            break;
        case 4:
            desativarProdutoPorCodigo();
            break;
        case 5:
            printf("Encerrando programa...\n");
            system("PAUSE");
            break;
        default:
            printf("Opcao invalida.\n");
            printf("****************\n");
            printf("****************\n");
            break;
        }

    } while (opcaoSelecionada != 5);

    return 0;
}