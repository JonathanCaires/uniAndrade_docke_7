#include <stdio.h>
#include <string.h>

#define MAX_EMPRESTIMOS 3

typedef enum{
    DISPONIVEL,
    EMPRESTADO
}StatusLivro;

typedef struct{
    char autor[40];
    char titulo[100];
    int total_emprestimos;
    StatusLivro status;
}Livro;

void imprimirLivro(Livro *livro){
    printf("\nTT_____________________________________________________TT\n");
    printf("||---------------BIBLIOTECA DE ALEXANDRIA--------------||\n");
    printf("||           Título: %s                              \n", livro -> titulo);
    printf("||           Autor: %s                               \n", livro -> autor);
    printf("||           Empréstimos: %d                         \n", livro -> total_emprestimos);
    if (livro -> total_emprestimos == 0){
        printf("||                    Título: 3 %s                \n", livro -> status == DISPONIVEL ? "Disponível" : "Emprestado");
    }else{
    printf("||           Título: %d %s                        \n",livro -> total_emprestimos, livro -> status == DISPONIVEL ? "Disponível" : "Emprestado");
    }
    printf("||------------------------------------------------------||\n");
    printf("LJ______________________________________________________LJ\n");
}

void emprestimoLivro(Livro *livro){
    printf("\nTT_____________________________________________________TT\n");
    printf("||-----------------EMPRESTIMO DE EXEMPLAR--------------||\n");
    if(livro -> total_emprestimos >= MAX_EMPRESTIMOS){
        printf("||\n     O livro '%s' já está com todos os exemplares emprestados!\n", livro -> titulo);
    }else{
        livro -> total_emprestimos++;
        livro -> status = EMPRESTADO;
        printf("||\n     Empréstimo realizado com sucesso!\n");
    }
    printf("||------------------------------------------------------||\n");
    printf("LJ______________________________________________________LJ\n");
    imprimirLivro(livro);
}

void devolverLivro(Livro *livro){
    printf("\nTT_____________________________________________________TT\n");
    printf("||------------------DEVOLUÇÃO DE EXEMPLAR--------------||\n");
    if(livro -> status == DISPONIVEL){
        printf("||\n     O livro '%s' já está disponível na biblioteca!\n", livro -> titulo);
    }else{
        livro -> total_emprestimos--;
        livro -> status = DISPONIVEL;
        printf("||\n     Devolução realizada com sucesso!\n");
    }
    printf("||------------------------------------------------------||\n");
    printf("LJ______________________________________________________LJ\n");
    imprimirLivro(livro);
}

int main(){
    Livro livro1 = {"J.R.R Tolkien", "Hobbit", 0, DISPONIVEL};
    imprimirLivro (&livro1);

    emprestimoLivro(&livro1);
    devolverLivro(&livro1);
    emprestimoLivro(&livro1);
    emprestimoLivro(&livro1);
    emprestimoLivro(&livro1);
    emprestimoLivro(&livro1);
    devolverLivro(&livro1);

    return 0;
}
