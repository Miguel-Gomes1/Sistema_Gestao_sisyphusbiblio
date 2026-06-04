#include <stdio.h>
#include <locale.h>

#define MAX 100

int main(){
    setlocale(LC_ALL, "Portuguese");
    int idsLivro[MAX];
    char titulos[MAX][100];
    char autores[MAX][100];
    int ativo[MAX];
    int totalLivros = 0;
    int opcao, opcaoLivros;
    int i, id, idx, encontrou, confirmacao;
    char busca[100];

    int idsUsuario[MAX];
    char nomes[MAX][100];
    char emails[MAX][100];
    char telefones[MAX][20];
    int ativoUsuario[MAX];
    int totalUsuarios = 0;

    do{
        printf("\n===SISIPHUSBIBLIO===\n");
        printf("\n1.Livros\n");
        printf("\n2.Usuários");
        printf("\n3.Empréstimos\n");
        printf("\n4.Devoluções\n");
        printf("\n5.Histórico\n");
        printf("\n0.Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao){
        case 1:
            printf("\n1.Cadastrar livros\n");
            printf("\n2.Listar livros\n");
            printf("\n3.Buscar livro\n");
            printf("\n4.Editar livro\n");
            printf("\n5.Ativar/Desativar livro\n");
            printf("\n0.Voltar\n");
            scanf("%d", &opcaoLivros);

            switch(opcaoLivros){
                case 1:
                printf("\n")
            }
            break;

        case 2:
            printf("\n1.Cadastrar usuário\n");
            printf("\n2.Listar usuários\n");
            printf("\n3.Buscar usuário\n");
            printf("\n4.Editar informação de usuário\n");
            printf("\n5.Ativar/Desativar usuário\n");
            printf("\n0.Voltar\n");
            break;

        case 3:
            printf("\n1.Realizar empréstimo\n");
            printf("\n2.Listar empréstimos ativos\n");
            printf("\n0.Voltar\n");
            break;

        case 4:
            printf("\n1.Registrar Devolução\n");
            printf("\n0.Voltar");
            break;

        case 5:
            printf("\n1.Histórico completo\n");
            printf("\n2.Filtrar por usuário\n");
            printf("\n3.Filtrar por livro\n");
            printf("\n0.Voltar\n");
            break;
        
        }
    }
}