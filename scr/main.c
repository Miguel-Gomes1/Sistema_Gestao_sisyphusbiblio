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

    do{
        printf("\n=== SISIPHUSBIBLIO ===\n");
        printf("1. Livros\n");
        printf("2. Usuarios\n");
        printf("3. Emprestimos\n");
        printf("4. Devolucoes\n");
        printf("5. Historico\n");
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
        printf("4. Editar livro\n");
        printf("5. Ativar/Desativar livro\n");
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
                printf("\nBuscar livro em desenvolvimento.\n");
                break;

            case 4:
                printf("\nEditar livro em desenvolvimento.\n");
                break;

            case 5:
                printf("\nAtivar/Desativar livro em desenvolvimento.\n");
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

        printf("\nCodigo: %d\n", livros[i].codigo);
        printf("Titulo: %s", livros[i].titulo);
        printf("Autor: %s", livros[i].autor);
    }
}