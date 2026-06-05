#include <stdio.h>
#include <locale.h>

#define MAX 100

struct Livro{
    int codigo;
    char titulo[200];
    char autor[100];
};

struct Livro livros[MAX];
int totalLivros = 0;

void menuLivros();
void cadastrarLivro();
void listarLivros();

int main(){
    setlocale(LC_ALL, "Portuguese");
    
    int opcao;
    int opcaoLivros;
   
    do{
        printf("\n===SISIPHUSBIBLIO===\n");
        printf("\n1. Livros");
        printf("\n2. Usuários");
        printf("\n3. Empréstimos");
        printf("\n4. Devoluções");
        printf("\n5. Histórico");
        printf("\n0. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        
        switch(opcao){
        case 1:
           menuLivros();
           break;

        case 2:
            printf("\n1.Cadastrar usuário\n");
            printf("\n2.Listar usuários\n");
            printf("\n3.Buscar usuário\n");
            printf("\n4.Editar informação de usuário\n");
            printf("\n5.Ativar/Desativar usuário\n");
            printf("\n0.Voltar\n");
            printf("\nEscolha uma opção: ");
            scanf("%d", &opcaoLivros);
            break;

        case 3:
            printf("\n1.Realizar empréstimo\n");
            printf("\n2.Listar empréstimos ativos\n");
            printf("\n0.Voltar\n");
            printf("\nEscolha uma opção: ");
            scanf("%d", &opcaoLivros);
            break;

        case 4:
            printf("\n1.Registrar Devolução\n");
            printf("\n0.Voltar");
            printf("\nEscolha uma opção: ");
            scanf("%d", &opcaoLivros);
            break;

        case 5:
            printf("\n1.Histórico completo\n");
            printf("\n2.Filtrar por usuário\n");
            printf("\n3.Filtrar por livro\n");
            printf("\n0.Voltar\n");
            printf("\nEscolha uma opção: ");
            scanf("%d", &opcaoLivros);
            break;
        default:
        printf("\nOpção inválida...\n");
        }
    } while (opcao != 0);
}

void menuLivros(){

    int opcaoLivros;
 
    do{
            printf("\n1. Cadastrar livros");
            printf("\n2. Listar livros");
            printf("\n3. Buscar livro");
            printf("\n4. Editar livro");
            printf("\n5. Ativar/Desativar livro");
            printf("\n0. Voltar");
            printf("\nEscolha uma opção: ");
            scanf("%d", &opcaoLivros);
            break;
    }
}while (opcao != 0);

void cadastrarLivro(){

    char titulo[100];
    char autor[100];

    getchar();

    printf("\n===CADASTRO DE LIVROS===\n");

    printf("Titulo: ")
    fgets("titulo,sizeof(titulo), stdin");

    printf("Autor: ")
    fgets("autor,sizeof(autor), stdin");

    printf("\n=== DADOS INFORMADOS ===\n");
    printf("Titulo: %s", titulo);
    printf("Autor: %s", autor);

    printf("\nLivro cadastrado com sucesso!\n");
}