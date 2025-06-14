# 📋 Sistema de Cadastro de Clientes

Um sistema completo de gerenciamento de clientes desenvolvido em linguagem C, com funcionalidades de cadastro, listagem, busca, edição e exclusão de registros.

## 📋 Descrição

Este projeto implementa um **Sistema de Cadastro de Clientes** robusto em linguagem C, utilizando estruturas de dados e manipulação de arquivos. O sistema permite gerenciar informações completas de clientes de forma eficiente e organizada.

## ✨ Funcionalidades

- **➕ Cadastro de Clientes**: Adicionar novos clientes ao sistema
- **📋 Listagem Completa**: Visualizar todos os clientes cadastrados
- **🔍 Busca por Nome**: Localizar clientes específicos
- **✏️ Edição de Dados**: Atualizar informações dos clientes
- **🗑️ Exclusão de Registros**: Remover clientes do sistema
- **🎂 Aniversários**: Controle de datas de aniversário
- **✅ Validação de Dados**: Verificação de duplicatas e formatos

## 🛠️ Tecnologias Utilizadas

- **Linguagem C**: Programação em C padrão (C99)
- **Estruturas (Structs)**: Organização dos dados
- **Arrays**: Armazenamento de múltiplos registros
- **Funções**: Modularização do código
- **Manipulação de Strings**: Processamento de texto

## 📊 Estrutura de Dados

### Estrutura Cliente:
```c
struct Cliente {
    char nome[50];             // Nome completo do cliente
    char telefone[30];         // Número de telefone
    char nomedaempresa[50];    // Nome da empresa
    char email[50];            // Endereço de e-mail
    int diadeaniversario;      // Dia do aniversário
    int mesdeaniversario;      // Mês do aniversário
};
```

### Características:
- **Capacidade**: Até 50 clientes simultaneamente
- **Validação**: Verificação de nomes duplicados
- **Interface**: Menu interativo no terminal

## 📁 Estrutura do Projeto

```
Cadastro-de-Clientes/
├── main.c              # Código fonte principal
├── LICENSE             # Licença do projeto
├── README.md           # Documentação
└── output/             # Arquivos compilados
    └── main.exe        # Executável para Windows
```

## 🚀 Como Compilar e Executar

### No Windows:
```bash
gcc main.c -o output/main.exe
./output/main.exe
```

### No Linux/Mac:
```bash
gcc main.c -o output/main
./output/main
```

### Usando Make (opcional):
```bash
make
./main
```

## 🎯 Menu do Sistema

```
=== SISTEMA DE CADASTRO DE CLIENTES ===
1. Cadastrar Cliente
2. Listar Todos os Clientes
3. Buscar Cliente por Nome
4. Editar Cliente
5. Excluir Cliente
6. Listar Aniversariantes do Mês
7. Sair do Sistema
```

## 💻 Funcionalidades Detalhadas

### 1. **Cadastro de Cliente**
- Entrada de dados: nome, telefone, empresa, email, aniversário
- Validação de nomes duplicados
- Confirmação de cadastro

### 2. **Listagem de Clientes**
- Exibição organizada de todos os registros
- Informações completas de cada cliente
- Navegação paginada (se necessário)

### 3. **Busca por Nome**
- Localização rápida de clientes
- Busca case-insensitive
- Exibição de resultados detalhados

### 4. **Edição de Dados**
- Atualização de informações específicas
- Manutenção da integridade dos dados
- Confirmação de alterações

### 5. **Exclusão de Registros**
- Remoção segura de clientes
- Confirmação antes da exclusão
- Reorganização automática do array

### 6. **Aniversariantes**
- Listagem por mês específico
- Organização por dia de aniversário
- Útil para campanhas de marketing

## 🔧 Funcionalidades Técnicas

- **Validação de Entrada**: Verificação de dados inseridos
- **Tratamento de Erros**: Gerenciamento de situações excepcionais
- **Interface Amigável**: Menu intuitivo e mensagens claras
- **Otimização de Memória**: Uso eficiente de estruturas
- **Modularização**: Funções bem definidas e reutilizáveis

## 📈 Possíveis Melhorias

- [ ] Persistência em arquivo (salvar/carregar dados)
- [ ] Interface gráfica (GTK ou similar)
- [ ] Sistema de backup automático
- [ ] Relatórios em PDF
- [ ] Integração com banco de dados
- [ ] Sistema de permissões de usuário
- [ ] Exportação para CSV/Excel
- [ ] Histórico de alterações

## 🎓 Conceitos Aprendidos

- **Estruturas de Dados**: Organização eficiente de informações
- **Manipulação de Strings**: Processamento de texto em C
- **Arrays e Ponteiros**: Gerenciamento de memória
- **Modularização**: Divisão do código em funções
- **Interface de Usuário**: Criação de menus interativos
- **Validação de Dados**: Garantia da integridade

## 📄 Licença

Este projeto está licenciado sob os termos especificados no arquivo LICENSE.

---

*Desenvolvido como projeto educacional para demonstrar programação em C e gerenciamento de dados* 📊