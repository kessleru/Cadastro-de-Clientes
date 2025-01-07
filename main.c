#include <stdio.h>
#include <string.h>
#define MAX 50

struct Cliente
{
    char nome[50];
    int telefone;
    char nomedaempresa[50];
    char email[50];
    int diadeaniversario;
    int mesdeaniversario;
};

struct Cliente clientes[MAX];

void inserirCliente(int i)
{
    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[i].nome);
    printf("Digite o telefone do cliente: ");
    scanf("%d", &clientes[i].telefone);
    printf("Digite o nome da empresa do cliente: ");
    scanf("%s", clientes[i].nomedaempresa);
    printf("Digite o email do cliente: ");
    scanf("%s", clientes[i].email);
    printf("Digite o dia do aniversario do cliente: ");
    scanf("%d", &clientes[i].diadeaniversario);
    printf("Digite o mes do aniversario do cliente: ");
    scanf("%d", &clientes[i].mesdeaniversario);
}

void alterarDados(int i)
{
    printf("Digite o nome do cliente: ");
    scanf("%s", clientes[i].nome);
    printf("Digite o telefone do cliente: ");
    scanf("%d", &clientes[i].telefone);
    printf("Digite o nome da empresa do cliente: ");
    scanf("%s", clientes[i].nomedaempresa);
    printf("Digite o email do cliente: ");
    scanf("%s", clientes[i].email);
    printf("Digite o dia do aniversario do cliente: ");
    scanf("%d", &clientes[i].diadeaniversario);
    printf("Digite o mes do aniversario do cliente: ");
    scanf("%d", &clientes[i].mesdeaniversario);
}

void excluirCliente(int i)
{
    clientes[i].nome[0] = '\0';
    clientes[i].telefone = 0;
    clientes[i].nomedaempresa[0] = '\0';
    clientes[i].email[0] = '\0';
    clientes[i].diadeaniversario = 0;
    clientes[i].mesdeaniversario = 0;
}

void ordenarClientes()
{
    struct Cliente temp;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            if (clientes[i].nome[0] != '\0' && clientes[j].nome[0] != '\0' && strcmp(clientes[i].nome, clientes[j].nome) > 0)
            {
                temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

void listarClientes()
{
    ordenarClientes();
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nome[0] != '\0')
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %d\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
}

void pesquisaNomeEmpresa(char nomeEmpresa[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nomedaempresa[0] != '\0' && strcmp(clientes[i].nomedaempresa, nomeEmpresa) == 0)
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %d\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
}

void pesquisaNomeCliente(char Nome[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nome[0] != '\0' && strcmp(clientes[i].nome, Nome) == 0)
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %d\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
}

int main()
{
    int opcao, i = 0;
    char nomeEmpresa[50], Nome[50];
    do
    {
        printf("1 - Inserir cliente\n");
        printf("2 - Alterar dados do cliente\n");
        printf("3 - Excluir cliente\n");
        printf("4 - Listar clientes\n");
        printf("5 - Pesquisar por nome da empresa\n");
        printf("6 - Pesquisar por nome do cliente\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inserirCliente(i);
            i++;
            break;
        case 2:
            printf("Digite o indice do cliente que deseja alterar: ");
            scanf("%d", &i);
            alterarDados(i);
            break;
        case 3:
            printf("Digite o indice do cliente que deseja excluir: ");
            scanf("%d", &i);
            excluirCliente(i);
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            printf("Digite o nome da empresa que deseja pesquisar: ");
            scanf("%s", nomeEmpresa);
            pesquisaNomeEmpresa(nomeEmpresa);
            break;
        case 6:
            printf("Digite o nome do cliente que deseja pesquisar: ");
            scanf("%s", Nome);
            pesquisaNomeCliente(Nome);
            break;
        }
    } while (opcao != 0);
    return 0;
}