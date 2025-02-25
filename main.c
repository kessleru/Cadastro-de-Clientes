#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 50  // Define o número máximo de clientes

// Definição da estrutura Cliente
struct Cliente
{
    char nome[50];             
    char telefone[30];              
    char nomedaempresa[50];    
    char email[50];            
    int diadeaniversario;     
    int mesdeaniversario;      
};

struct Cliente clientes[MAX]; // Array para armazenar os clientes, com limite de MAX clientes

// Funcao: pausarTela
// Descricao: Procedimento para pausar a tela e aguardar o usuário pressionar Enter
// Parametros: nenhum
//Retorno: nenhum
void pausarTela() {
    printf("Pressione Enter para continuar...");
    getchar();  // Captura o Enter que ficou no buffer
    getchar();  // Espera o usuário pressionar Enter
}

// Funcao: nomeExiste
// Descricao: Verifica se o nome já existe
// Parametros: char nome[] - nome a ser verificado
//Retorno: 1 se o nome já existe, 0 caso contrário
int nomeExiste(char nome[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(clientes[i].nome, nome) == 0) 
        {
            return 1; 
        }
    }
    return 0;  
}

// Funcao: telefoneExiste
// Descricao: Verifica se o telefone já existe
// Parametros: char telefone[] - telefone a ser verificado
//Retorno: 1 se o telefone já existe, 0 caso contrário
int telefoneExiste(char telefone[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].telefone == telefone) 
        {
            return 1;  
        }
    }
    return 0;  
}

// Funcao: emailExiste
// Descricao: Verifica se o email já existe
// Parametros: char email[] - email a ser verificado
//Retorno: 1 se o email já existe, 0 caso contrário
int emailExiste(char email[])
{
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(clientes[i].email, email) == 0)  
        {
            return 1;  
        }
    }
    return 0; 
}

// Funcao: inserirCliente
// Descricao: Procedimento para inserir um cliente na lista
// Parametros: int i - índice do cliente
//Retorno: nenhum
void inserirCliente(int i)
{
    system("cls");  // Limpa a tela
    printf("\n\n=====================================\n|           Inserir Cliente         |  \n=====================================\n");
    
    char nome[50], nomedaempresa[50], email[50], telefone[30];
    

    // Inserção do nome
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);
    while (nomeExiste(nome))  // Verifica se o nome já existe
    {
        printf("Nome já existe!\n");
        printf("Digite um nome diferente: ");
        scanf("%s", nome);
    }
    strcpy(clientes[i].nome, nome);  // Copia o nome para o cliente

    // Inserção do telefone
    printf("Digite o telefone do(a) %s: ", nome);
    scanf("%s", telefone);
    while (telefoneExiste(telefone))  // Verifica se o telefone já existe
    {
        printf("Telefone já existe!\n");
        printf("Digite um telefone diferente: ");
        scanf("%s", telefone);
    }
    strcpy(clientes[i].telefone, telefone);  // Atribui o telefone ao cliente

    // Inserção do nome da empresa
    printf("Digite o nome da empresa do(a) %s: ", nome);
    scanf("%s", nomedaempresa);
    strcpy(clientes[i].nomedaempresa, nomedaempresa);  // Atribui o nome da empresa ao cliente

    // Inserção do email
    printf("Digite o email do(a) %s: ", nome);
    scanf("%s", email);
    while (emailExiste(email))  // Verifica se o email já existe
    {
        printf("Email já existe!\n");
        printf("Digite um email diferente: ");
        scanf("%s", email);
    }
    strcpy(clientes[i].email, email);  // Atribui o email ao cliente

    // Inserção do dia do aniversário
    printf("Digite o dia do aniversario do(a) %s: ", nome);
    scanf("%d", &clientes[i].diadeaniversario);
    while (clientes[i].diadeaniversario < 1 || clientes[i].diadeaniversario > 31)  // Valida o dia
    {
        printf("Dia do aniversario invalido!\n");
        printf("Digite um dia entre 1 e 31: ");
        scanf("%d", &clientes[i].diadeaniversario); 
    }

    // Inserção do mês do aniversário
    printf("Digite o mes do aniversario do(a) %s: ", nome);
    scanf("%d", &clientes[i].mesdeaniversario);
    while (clientes[i].mesdeaniversario < 1 || clientes[i].mesdeaniversario > 12)  // Valida o mês
    {
        printf("Mes do aniversario invalido!\n");
        printf("Digite um mes entre 1 e 12: ");
        scanf("%d", &clientes[i].mesdeaniversario);
    }

    printf("\nCliente inserido com sucesso!\n");
}

// Funcao: alterarDados
// Descricao: Procedimento para alterar os dados de um cliente
// Parametros: nenhum
//Retorno: nenhum
void alterarDados()
{
    system("cls");  // Limpa a tela
    char nome[50];
    printf("\n\n=====================================\n|           Alterar Cliente         |  \n=====================================\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    // Busca o cliente pelo nome
    for (int i = 0; i < MAX; i++)
    {
        if (strcmp(clientes[i].nome, nome) == 0) 
        {
            inserirCliente(i);
        }
    }
    pausarTela();
}

// Funcao: excluirCliente
// Descricao: Procedimento para excluir um cliente da lista
// Parametros: nenhum
//Retorno: nenhum
void excluirCliente()
{
    char nome[50];
    system("cls");
    printf("\n\n=====================================\n|           Excluir Cliente         |  \n=====================================\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", nome);

    // Busca e exclui o cliente pelo nome
    for (int j = 0; j < MAX; j++)
    {
        if (strcmp(clientes[j].nome, nome) == 0)
        {
            printf("Excluindo cliente: %s\n", clientes[j].nome);
            clientes[j].nome[0] = '\0';  // Limpa os dados do cliente
            clientes[j].telefone[0] = '\0';
            clientes[j].nomedaempresa[0] = '\0';
            clientes[j].email[0] = '\0';
            clientes[j].diadeaniversario = 0;
            clientes[j].mesdeaniversario = 0;
            printf("Cliente excluido com sucesso.\n");
            pausarTela();
            return;
        }
    }
    printf("Cliente nao encontrado.\n");
    pausarTela();
}

// Funcao: ordenarClientes
// Descricao: Procedimento para ordenar os clientes por nome
// Parametros: nenhum
//Retorno: nenhum
void ordenarClientes()
{
    struct Cliente temp;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i + 1; j < MAX; j++)
        {
            // Compara os nomes e troca os clientes de lugar se necessário
            if (clientes[i].nome[0] != '\0' && clientes[j].nome[0] != '\0' && strcmp(clientes[i].nome, clientes[j].nome) > 0)
            {
                temp = clientes[i];
                clientes[i] = clientes[j];
                clientes[j] = temp;
            }
        }
    }
}

// Funcao: listarClientes
// Descricao: Lista todos os clientes cadastrados
// Parametros: nenhum
//Retorno: nenhum
void listarClientes()
{
    system("cls");
    printf("\n\n=====================================\n|        Listagem dos clientes      |  \n=====================================\n");

    ordenarClientes();  // Ordena os clientes por nome
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nome[0] != '\0')  // Se o cliente estiver cadastrado, exibe seus dados
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
    pausarTela();
}

// Funcao: pesquisaNomeEmpresa
// Descricao: Pesquisa por clientes cuja empresa é exatamente igual à indicada
// Parametros: nenhum
//Retorno: nenhum
void pesquisaNomeEmpresa()
{
    system("cls");
    char nomeEmpresa[50];
    printf("\n\n=====================================\n|   Pesquisar cliente por empresa   |  \n=====================================\n");

    printf("Digite o nome da empresa: ");
    scanf("%s", nomeEmpresa);

    // Busca por clientes que pertencem à empresa indicada
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nomedaempresa[0] != '\0' && strcmp(clientes[i].nomedaempresa, nomeEmpresa) == 0)
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
    pausarTela();
}

// Funcao: pesquisaNomeCliente
// Descricao: Pesquisa por clientes cujo nome é exatamente igual ao indicado
// Parametros: nenhum
//Retorno: nenhum
void pesquisaNomeCliente()
{
    system("cls");
    char Nome[50];
    printf("\n\n=====================================\n|     Pesquisar cliente por nome    |  \n=====================================\n");
    printf("Digite o nome do cliente: ");
    scanf("%s", Nome);

    // Busca pelo nome exato do cliente
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nome[0] != '\0' && strcmp(clientes[i].nome, Nome) == 0)
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
    pausarTela();
}

// Funcao: pesquisarCaractere
// Descricao: Pesquisa por clientes cujo nome começa com o caractere indicado
// Parametros: nenhum
// Retorno: nenhum
void pesquisarCaractere()
{
    char c;
    system("cls");
    printf("\n\n=====================================\n|     Pesquisar por caractere    |  \n=====================================\n");

    printf("Digite o caractere: ");
    scanf(" %c", &c);

    // Busca clientes cujo nome começa com o caractere indicado
    for (int i = 0; i < MAX; i++)
    {
        if (clientes[i].nome[0] != '\0' && clientes[i].nome[0] == c)
        {
            printf("Nome: %s\n", clientes[i].nome);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Nome da empresa: %s\n", clientes[i].nomedaempresa);
            printf("Email: %s\n", clientes[i].email);
            printf("Dia do aniversario: %d\n", clientes[i].diadeaniversario);
            printf("Mes do aniversario: %d\n", clientes[i].mesdeaniversario);
            printf("\n");
        }
    }
    pausarTela();
}   

// Função principal, com o menu de opções
int main()
{
    int opcao, i = 0;
    do
    {
        system("cls");
        printf("\n=====================================\n|        CADASTRO DE CLIENTES       |\n=====================================\n| 1. Inserir cliente                |\n| 2. Alterar cliente                |\n| 3. Excluir cliente                |\n| 4. Listar clientes                |\n| 5. Pesquisar cliente por empresa  |\n| 6. Pesquisar cliente por nome     |\n| 7. Pesquisar por caractere        |\n|                                   |\n|       -> Digite uma opcao <-      |\n=====================================\n"); 
        scanf("%d", &opcao);  // Lê a opção escolhida pelo usuário
        switch (opcao)
        {
        case 1:
            inserirCliente(i);  // Chama a função para inserir cliente
            i++;  // Incrementa o índice
            pausarTela();
            break;
        case 2:
            alterarDados();  // Chama a função para alterar dados do cliente
            break;
        case 3:
            excluirCliente();  // Chama a função para excluir cliente
            break;
        case 4:
            listarClientes();  // Chama a função para listar os clientes
            break;
        case 5:
            pesquisaNomeEmpresa();  // Pesquisa por empresa
            break;
        case 6:
            pesquisaNomeCliente();  // Pesquisa por nome
            break;
        case 7:
            pesquisarCaractere();  // Pesquisa por caractere
            break;
        }

    } while (opcao != 0);  // O loop continua até que a opção 0 seja escolhida (sair)
    return 0;
}
