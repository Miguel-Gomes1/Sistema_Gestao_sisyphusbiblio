#include <stdio.h>
#include <locale.h>

#define MAX 100

struct Livro{
    int codigo;
    char titulo[200];
    char autor[100];
    int status;
};

struct Livro livros[MAX];
int totalLivros = 0;

void menuLivros();
void cadastrarLivro();
void listarLivros();
void buscarLivro();
void ativarDesativarLivro();

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do{
        printf("\n=== SISIPHUSBIBLIO ===\n");
        printf("1. Livros\n");
        printf("2. Usuários\n");
        printf("3. Empréstimos\n");
        printf("4. Devoluções\n");
        printf("5. Histórico\n");
        printf("0. Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                menuLivros();
                break;

            case 2:
                printf("\nModulo Usuarios em desenvolvimento.\n");
                break;

            case 3:
                printf("\nModulo Emprestimos em desenvolvimento.\n");
                break;

            case 4:
                printf("\nModulo Devolucoes em desenvolvimento.\n");
                break;

            case 5:
                printf("\nModulo Historico em desenvolvimento.\n");
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