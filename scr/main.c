#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100

struct Livro{
    int codigo;
    char titulo[200];
    char autor[100];
    int status;
};

struct Usuario{
    int codigo;
    char nome[100];
    char cpf[20];
    char telefone[20];
    char email[100];
    int status;
};

struct Emprestimo{
    int codigo;
    int codigoUsuario;
    int codigoLivro;
    int status;
};

struct Livro livros[MAX];
int totalLivros = 0;

struct Usuario usuarios[MAX];
int totalUsuarios = 0;

struct Emprestimo emprestimos[MAX];
int totalEmprestimos = 0;

//livros
void menuLivros();
void cadastrarLivro();
void listarLivros();
void buscarLivro();
void ativarDesativarLivro();

//usuarios
void menuUsuarios();
void cadastrarUsuario();
void listarUsuario();
void buscarUsuario();
void ativarDesativarUsuario();

//emprestims e devoluções
void menuEmprestimos();
void realizarEmprestimo();
void listarEmprestimos();
void menuDevolucoes();
void registrarDevolucao();

//listagem geral sobre tudo
void menuHistorico();
void historicoCompleto();
void historicoPorUsuario();
void historicoPorLivro();

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do{
        printf("\n=== SISIPHUSBIBLIO ===\n");
        printf("1. Livros\n");
        printf("2. Usuários\n");
        printf("3. Empréstimos\n");
        printf("4. Histórico\n");
        printf("0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                menuLivros();
                break;

            case 2:
                menuUsuarios();
                break;

            case 3:
                menuEmprestimos();
                break;

            case 4:
                menuHistorico();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}

void menuLivros(){

    int opcaoLivros;

    do{
        printf("\n=== MENU LIVROS ===\n");
        printf("1. Cadastrar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livro\n");
        printf("4. Ativar/Desativar livro\n");
        printf("0. Voltar\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcaoLivros);

        switch(opcaoLivros){
            case 1:
                cadastrarLivro();
                break;

            case 2:
                listarLivros();
                break;

            case 3:
                buscarLivro();
                break;

            case 4:
                ativarDesativarLivro();
                break;

            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcaoLivros != 0);
}

void menuUsuarios(){
    int opcaoUsuarios;

    do{
        printf("\n=== MENU USUÁRIOS ===\n");
        printf("1. Cadastrar usuário\n");
        printf("2. Listar usuários\n");
        printf("3. Buscar usuário\n");
        printf("4. Ativar/Desativar usuário\n");
        printf("0. voltar\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoUsuarios);

        switch(opcaoUsuarios)
        {
            case 1:
                cadastrarUsuario();
                break;

            case 2:
                listarUsuario();
                break;

            case 3:
                buscarUsuario();
                break;

            case 4:
                ativarDesativarUsuario();
                break;

            case 0:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao inválida!\n");
        }

    }while(opcaoUsuarios != 0);
}

void menuEmprestimos(){
    int opcaoEmprestimos;

    do{
        printf("\n=== MENU EMPRÉSTIMOS ===\n");
        printf("1. Realizar empréstimo\n");
        printf("2. Listar empréstimos\n");
        printf("3. Realizar devolução\n");
        printf("0. Voltar\n");

        printf("\nEscolha uma opção: ");
        scanf("%d", &opcaoEmprestimos);

        switch(opcaoEmprestimos)
        {
            case 1:
                realizarEmprestimo();
                break;

            case 2:
                listarEmprestimos();
                break;

            case 3:
                registrarDevolucao();
                break;

            case 0:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao inválida!\n");
        }

    }while(opcaoEmprestimos != 0);
    
}

void menuHistorico(){

    int opcaoHistorico;

    do{

        printf("\n=== HISTORICO ===\n");
        printf("1. Historico completo\n");
        printf("2. Filtrar por usuário\n");
        printf("3. Filtrar por livro\n");
        printf("0. Voltar\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcaoHistorico);

        switch(opcaoHistorico){

            case 1:
                historicoCompleto();
                break;

            case 2:
                historicoPorUsuario();
                break;

            case 3:
                historicoPorLivro();
                break;

            case 0:
                printf("\nVoltando...\n");
                break;

            default:
                printf("\nOpcao inválida!\n");
        }

    }while(opcaoHistorico != 0);
}

//LIVROS

void cadastrarLivro(){

    if(totalLivros >= MAX){
        printf("\nLimite de livros atingido!!!!\n");
        return;
    }

    printf("\n=== CADASTRO DE LIVRO ===\n");

    livros[totalLivros].codigo = totalLivros + 1;

    getchar();

    printf("Titulo: ");
    fgets(livros[totalLivros].titulo,
          sizeof(livros[totalLivros].titulo),
          stdin);

    printf("Autor: ");
    fgets(livros[totalLivros].autor,
          sizeof(livros[totalLivros].autor),
        stdin);
    livros[totalLivros].status = 1;
    totalLivros++;

    printf("\nLivro cadastrado com sucesso!\n");
}

void listarLivros(){

    int i;

    printf("\n=== LIVROS CADASTRADOS ===\n");

    if(totalLivros == 0){
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for(i = 0; i < totalLivros; i++){

        printf("\n---------------------------");
        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Titulo: %s", livros[i].titulo);
        printf("Autor: %s", livros[i].autor);
        printf("Status: ");

        if(livros[i].status == 1)
        {
        printf("Ativo\n");
        }else{
        printf("Inativo\n");
            }
    }
}

void buscarLivro(){
    int i;
    int codigoBuscado;
    int encontrou = 0;

    printf("\n=== Buscar Livro ===\n");
    
    printf("Digite o código do livro: ");
    scanf("%d", &codigoBuscado);

    for(i = 0; i < totalLivros; i++)
    {
        if(livros[i].codigo == codigoBuscado)
        {
            printf("\nLivro encontrado!\n");

            printf("Codigo: %d\n", livros[i].codigo);
            printf("Titulo: %s", livros[i].titulo);
            printf("Autor: %s", livros[i].autor);

            printf("Status: ");

            if(livros[i].status == 1)
            {
                printf("Ativo\n");
            }
            else
            {
                printf("Inativo\n");
            }

            encontrou = 1;
            break;
        }
    }

    if(encontrou == 0)
    {
        printf("\nLivro nao encontrado.\n");
    }
}


void  ativarDesativarLivro(){
    int codigo;
    int i; 

    printf("\nDigite o código do livro: ");
    scanf("%d", &codigo);

    for(i = 0; i < totalLivros; i++)
    {
        if(livros[i].codigo == codigo)
        {
        if(livros[i].status == 1)
            {
                livros[i].status = 0;
                printf("\nLivro inativado.\n");
            }
            else
            {
                livros[i].status = 1;
                printf("\nLivro ativado.\n");
            }

            return;
        }
    }

    printf("\nLivro nao encontrado.\n");
}

//USUÁRIOS
void cadastrarUsuario()
{
    int i;
    int cpfExiste = 0;

    if(totalUsuarios >= MAX)
    {
        printf("\nLimite de usuarios atingido!\n");
        return;
    }

    usuarios[totalUsuarios].codigo = totalUsuarios + 1;

    getchar();

    printf("\n=== CADASTRO DE USUARIO ===\n");

    printf("Nome: ");
    fgets(usuarios[totalUsuarios].nome,
          sizeof(usuarios[totalUsuarios].nome),
          stdin);

    printf("CPF: ");
    fgets(usuarios[totalUsuarios].cpf,
          sizeof(usuarios[totalUsuarios].cpf),
          stdin);

          for(i = 0; i < totalUsuarios; i++)
        {
    if(strcmp(usuarios[i].cpf,usuarios[totalUsuarios].cpf) == 0){
        cpfExiste = 1;
        break;
            }
        }

    if(cpfExiste == 1){

    printf("\nCPF ja cadastrado!\n");
    return;
    }

    printf("Telefone: ");
    fgets(usuarios[totalUsuarios].telefone,
          sizeof(usuarios[totalUsuarios].telefone),
          stdin);

    printf("Email: ");
    fgets(usuarios[totalUsuarios].email,
          sizeof(usuarios[totalUsuarios].email),
          stdin);

    usuarios[totalUsuarios].status = 1;

    totalUsuarios++;

    printf("\nUsuario cadastrado com sucesso!\n");
}

void listarUsuario()
{
    int i;

    if(totalUsuarios == 0)
    {
        printf("\nNenhum usuario cadastrado.\n");
        return;
    }

    for(i = 0; i < totalUsuarios; i++)
    {
        printf("\n====================\n");
        printf("Codigo: %d\n",usuarios[i].codigo);
        printf("Nome: %s",usuarios[i].nome);
        printf("CPF: %s", usuarios[i].cpf);
        printf("Telefone: %s", usuarios[i].telefone);
        printf("Email: %s", usuarios[i].email);

        printf("Status: ");

        if(usuarios[i].status == 1)
        {
            printf("Ativo\n");
        }
        else
        {
            printf("Inativo\n");
        }
    }
}

void buscarUsuario(){

    int i;
    int codigoBuscado;
    int encontrou = 0;

    printf("\n=== BUSCAR USUARIO ===\n");

    printf("Digite o codigo do usuario: ");
    scanf("%d", &codigoBuscado);

    for(i = 0; i < totalUsuarios; i++)
    {
        if(usuarios[i].codigo == codigoBuscado)
        {
            printf("\nUsuario encontrado!\n");

            printf("Codigo: %d\n", usuarios[i].codigo);
            printf("Nome: %s", usuarios[i].nome);
            printf("CPF: %s", usuarios[i].cpf);
            printf("Telefone: %s", usuarios[i].telefone);
            printf("Email: %s", usuarios[i].email);

            printf("Status: ");

            if(usuarios[i].status == 1)
            {
                printf("Ativo\n");
            }
            else
            {
                printf("Inativo\n");
            }

            encontrou = 1;
            break;
        }
    }

    if(encontrou == 0)
    {
        printf("\nUsuario nao encontrado.\n");
    }
}

void ativarDesativarUsuario(){

    int codigo;
    int i;

    printf("\nDigite o codigo do usuario: ");
    scanf("%d", &codigo);

    for(i = 0; i < totalUsuarios; i++){

        if(usuarios[i].codigo == codigo){

            if(usuarios[i].status == 1){

                usuarios[i].status = 0;
                printf("\nUsuario inativado.\n");
            }
            else{

                usuarios[i].status = 1;
                printf("\nUsuario ativado.\n");
            }

            return;
        }
    }

    printf("\nUsuario nao encontrado.\n");
}

void realizarEmprestimo(){

    if(totalEmprestimos >= MAX){

        printf("\nLimite de emprestimos atingido!\n");
        return;
    }

    printf("\n=== REALIZAR EMPRESTIMO ===\n");

    emprestimos[totalEmprestimos].codigo = totalEmprestimos + 1;

    printf("Codigo do usuario: ");
    scanf("%d", &emprestimos[totalEmprestimos].codigoUsuario);

    printf("Codigo do livro: ");
    scanf("%d", &emprestimos[totalEmprestimos].codigoLivro);

    emprestimos[totalEmprestimos].status = 1;

    totalEmprestimos++;

    printf("\nEmprestimo registrado com sucesso!\n");
}

void listarEmprestimos(){
    int i;

    printf("\n=== EMPRESTIMOS CADASTRADOS ===\n");

    if(totalEmprestimos == 0){

        printf("\nNenhum emprestimo cadastrado.\n");
        return;
    }

    for(i = 0; i < totalEmprestimos; i++){

        printf("\n====================\n");
        printf("Codigo de empréstimo: %d\n",
               emprestimos[i].codigo);

        printf("Usuario: %d\n",
               emprestimos[i].codigoUsuario);

        printf("Livro: %d\n",
               emprestimos[i].codigoLivro);

        printf("Status: ");

        if(emprestimos[i].status == 1){

            printf("Ativo\n");
        }
        else{

            printf("Devolvido\n");
        }
    }
}

void registrarDevolucao(){

    int codigoEmprestimo;
    int i;

    printf("\n=== REGISTRAR DEVOLUCAO ===\n");

    printf("Digite o codigo do emprestimo: ");
    scanf("%d", &codigoEmprestimo);

    for(i = 0; i < totalEmprestimos; i++){

        if(emprestimos[i].codigo == codigoEmprestimo){

            if(emprestimos[i].status == 0){

                printf("\nEste emprestimo ja foi devolvido.\n");
                return;
            }

            emprestimos[i].status = 0;

            printf("\nDevolucao registrada com sucesso!\n");
            return;
        }
    }

    printf("\nEmprestimo nao encontrado.\n");
}

void historicoCompleto(){
    int i;

    printf("\n=== HISTORICO COMPLETO ===\n");

    if(totalEmprestimos == 0)
    {
        printf("\nNenhum emprestimo registrado.\n");
        return;
    }

    for(i = 0; i < totalEmprestimos; i++)
    {
        printf("\nCodigo: %d\n",
               emprestimos[i].codigo);

        printf("Usuario: %d\n",
               emprestimos[i].codigoUsuario);

        printf("Livro: %d\n",
               emprestimos[i].codigoLivro);

        printf("Status: ");

        if(emprestimos[i].status == 1)
        {
            printf("Ativo\n");
        }
        else
        {
            printf("Devolvido\n");
        }

        printf("------------------\n");
    }
}

void historicoPorUsuario(){
    int codigoUsuario;
    int i;
    int encontrou = 0;

    printf("\n=== HISTORICO POR USUARIO ===\n");

    printf("Digite o codigo do usuario: ");
    scanf("%d", &codigoUsuario);

    for(i = 0; i < totalEmprestimos; i++)
    {
        if(emprestimos[i].codigoUsuario == codigoUsuario)
        {
            printf("\nCodigo Emprestimo: %d\n",
                   emprestimos[i].codigo);

            printf("Usuario: %d\n",
                   emprestimos[i].codigoUsuario);

            printf("Livro: %d\n",
                   emprestimos[i].codigoLivro);

            printf("Status: ");

            if(emprestimos[i].status == 1)
            {
                printf("Ativo\n");
            }
            else
            {
                printf("Devolvido\n");
            }

            encontrou = 1;
        }
    }

    if(encontrou == 0)
    {
        printf("\nNenhum emprestimo encontrado para este usuario.\n");
    }
}

void historicoPorLivro(){
    int codigoLivro;
    int i;
    int encontrou = 0;

    printf("\n=== HISTORICO POR LIVRO ===\n");

    printf("Digite o codigo do livro: ");
    scanf("%d", &codigoLivro);

    for(i = 0; i < totalEmprestimos; i++){

        if(emprestimos[i].codigoLivro == codigoLivro)
        {
            printf("\nCodigo Emprestimo: %d\n",
                   emprestimos[i].codigo);

            printf("Usuario: %d\n",
                   emprestimos[i].codigoUsuario);

            printf("Livro: %d\n",
                   emprestimos[i].codigoLivro);

            printf("Status: ");

            if(emprestimos[i].status == 1)
            {
                printf("Ativo\n");
            }
            else
            {
                printf("Devolvido\n");
            }

            encontrou = 1;
        }
    }

    if(encontrou == 0)
    {
        printf("\nNenhum emprestimo encontrado para este livro.\n");
    }
}