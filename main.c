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
    printf("\n\n=====================================\n|           Inserir Cliente         |  \n=====================================\n");
    
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
    printf("\n\n=====================================\n|           Alterar Cliente         |  \n=====================================\n");

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
     printf("\n\n=====================================\n|           Excluir Cliente         |  \n=====================================\n");
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
     printf("\n\n=====================================\n|        Listagem dos clientes     |  \n=====================================\n");

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
    printf("\n\n=====================================\n|   Pesquisar cliente por empresa   |  \n=====================================\n");

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
    printf("\n\n=====================================\n|     Pesquisar cliente por nome    |  \n=====================================\n");

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
        printf("\n=====================================\n|        CADASTRO DE CLIENTES       |\n=====================================\n| 1. Inserir cliente                |\n| 2. Alterar cliente                |\n| 3. Excluir cliente                |\n| 4. Listar clientes                |\n| 5. Pesquisar cliente por empresa  |\n| 6. Pesquisar cliente por nome     |\n=====================================\n         Escolha uma opcao: "); 
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inserirCliente(i);
            i++;
            break;
        case 2:
            alterarDados(i);
            break;
        case 3:
            excluirCliente(i);
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            pesquisaNomeEmpresa(nomeEmpresa);
            break;
        case 6:
            pesquisaNomeCliente(Nome);
            break;
        }
    } while (opcao != 0);
    return 0;
}
