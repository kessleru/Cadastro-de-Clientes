#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void pausarTela() {
    printf("Pressione Enter para continuar...");
    getchar(); // Captura o Enter que ficou no buffer
    getchar(); // Espera o usuário pressionar Enter
}

int nomeExiste(char nome[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(clientes[i].nome, nome) == 0)
        {
            return 1; // Cliente já existe
        }
    }
    return 0; // Cliente não existe
}

int telefoneExiste(int telefone)
{
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].telefone == telefone)
        {
            return 1; // Telefone já existe
        }
    }
    return 0; // Telefone não existe
}

int emailExiste(char email[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(clientes[i].email, email) == 0)
        {
            return 1; // Email já existe
        }
    }
    return 0; // Email não existe
}

void inserirCliente(int i)
{
    system("cls");
    printf("\n\n=====================================\n|           Inserir Cliente         |  \n=====================================\n");
    
    char nome[50], nomedaempresa[50], email[50];
    int telefone;

    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    while (nomeExiste(nome))
    {
        printf("Nome já existe!\n");
        printf("Digite um nome diferente: ");
        scanf("%s", nome);
    }
    strcpy(clientes[i].nome, nome);

    printf("Digite o telefone do cliente: ");
    scanf("%d", &telefone);
    while (telefoneExiste(telefone))
    {
        printf("Telefone já existe!\n");
        printf("Digite um telefone diferente: ");
        scanf("%d", &telefone);
    }
    clientes[i].telefone = telefone;

    printf("Digite o nome da empresa do cliente: ");
    scanf("%s", nomedaempresa);
    strcpy(clientes[i].nomedaempresa, nomedaempresa);

    printf("Digite o email do cliente: ");
    scanf("%s", email);
    while (emailExiste(email))
    {
        printf("Email já existe!\n");
        printf("Digite um email diferente: ");
        scanf("%s", email);
    }
    strcpy(clientes[i].email, email);

    printf("Digite o dia do aniversario do cliente: ");
    scanf("%d", &clientes[i].diadeaniversario);
    while (clientes[i].diadeaniversario < 1 || clientes[i].diadeaniversario > 31)
    {
        printf("Dia do aniversario invalido!\n");
        printf("Digite um dia entre 1 e 31: ");
        scanf("%d", &clientes[i].diadeaniversario); 
    }

    printf("Digite o mes do aniversario do cliente: ");
    scanf("%d", &clientes[i].mesdeaniversario);
    while (clientes[i].mesdeaniversario < 1 || clientes[i].mesdeaniversario > 12)
    {
        printf("Mes do aniversario invalido!\n");
        printf("Digite um mes entre 1 e 12: ");
        scanf("%d", &clientes[i].mesdeaniversario);
    }

    printf("\nCliente inserido com sucesso!\n");
}

void alterarDados()
{
    system("cls");
    char nome[50];
    printf("\n\n=====================================\n|           Alterar Cliente         |  \n=====================================\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(clientes[i].nome, nome) == 0)
        {
            inserirCliente(i);
        }
    }
    pausarTela();
}

void excluirCliente()
{
    char nome[50];
    system("cls");
    printf("\n\n=====================================\n|           Excluir Cliente         |  \n=====================================\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    for (int j = 0; j < MAX; j++)
    {
        if (strcmp(clientes[j].nome, nome) == 0)
        {
            printf("Excluindo cliente: %s\n", clientes[j].nome);
            clientes[j].nome[0] = '\0';
            clientes[j].telefone = 0;
            clientes[j].nomedaempresa[0] = '\0';
            clientes[j].email[0] = '\0';
            clientes[j].diadeaniversario = 0;
            clientes[j].mesdeaniversario = 0;
            printf("Cliente excluído com sucesso.\n");
            pausarTela();
            return;
        }
    }
    printf("Cliente nao encontrado.\n");
    pausarTela();
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
    system("cls");
     printf("\n\n=====================================\n|        Listagem dos clientes      |  \n=====================================\n");

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
    pausarTela();
}

void pesquisaNomeEmpresa()
{
    system("cls");
    char nomeEmpresa[50];
    printf("\n\n=====================================\n|   Pesquisar cliente por empresa   |  \n=====================================\n");

    printf("Digite o nome da empresa: ");
    scanf("%s", nomeEmpresa);

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
    pausarTela();
}

void pesquisaNomeCliente()
{
    system("cls");
    char Nome[50];
    printf("\n\n=====================================\n|     Pesquisar cliente por nome    |  \n=====================================\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", Nome);

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
    pausarTela();
}

void pesquisarCaractere()
{
    char c;
    system("cls");
    printf("\n\n=====================================\n|     Pesquisar por caractere    |  \n=====================================\n");

    printf("Digite o caractere: ");
    scanf(" %c", &c);
    printf("\n");

    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nome[0] != '\0' && clientes[i].nome[0] == c)
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
    pausarTela();
}


int main()
{
    
    int opcao, i = 0;
    do
    {
        system("cls");
        printf("\n=====================================\n|        CADASTRO DE CLIENTES       |\n=====================================\n| 1. Inserir cliente                |\n| 2. Alterar cliente                |\n| 3. Excluir cliente                |\n| 4. Listar clientes                |\n| 5. Pesquisar cliente por empresa  |\n| 6. Pesquisar cliente por nome     |\n| 7. Pesquisar por caractere        |\n|                                   |\n|       -> Digite uma opcao <-      |\n=====================================\n"); 
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inserirCliente(i);
            i++;
            pausarTela();
            break;
        case 2:
            alterarDados();
            break;
        case 3:
            excluirCliente();
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            pesquisaNomeEmpresa();
            break;
        case 6:
            pesquisaNomeCliente();
            break;
        
        case 7:
            pesquisarCaractere();
            break;
        }

    } while (opcao != 0);
    return 0;
}