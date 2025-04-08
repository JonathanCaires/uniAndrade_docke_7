#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

#define MAX_EMPRESTIMOS 3
#define MAX_LIVROS 100
#define LIVROS_POR_PAGINA 3

typedef struct {
    char titulo[100];
    char autor[40];
    char genero[40];
    char sinopse[300];
    int estoque;
    int emprestados;
} Livro;

Livro biblioteca[MAX_LIVROS] = {
    {"O Hobbit", "J.R.R. Tolkien", "Fantasia", "A aventura de Bilbo Bolseiro, um hobbit que parte em uma jornada inesperada.", 3, 0},
    {"1984", "George Orwell", "Distopia", "Uma sociedade controlada pelo Grande Irmão, onde a liberdade é uma ilusão.", 3, 0},
    {"Dom Quixote", "Miguel de Cervantes", "Clássico", "A jornada louca e hilariante de um homem que quer ser cavaleiro.", 3, 0}
};
int numLivros = 3;

void limparTela() {
    system(CLEAR);
}

void imprimirLivro(Livro *livro) {
    printf("\n--------------------------------\n");
    printf("Título: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Gênero: %s\n", livro->genero);
    printf("Sinopse: %s\n", livro->sinopse);
    printf("Disponíveis: %d\n", livro->estoque - livro->emprestados);
    printf("Emprestados: %d\n", livro->emprestados);
    printf("--------------------------------\n");
}

void listarLivrosPaginado() {
    int pagina = 0;
    char continuar;
    do {
        limparTela();
        printf("\nLista de Livros - Página %d\n", pagina + 1);
        for (int i = pagina * LIVROS_POR_PAGINA; i < (pagina + 1) * LIVROS_POR_PAGINA && i < numLivros; i++) {
            printf("%d - %s\n", i, biblioteca[i].titulo);
        }
        printf("Pressione 'n' para próxima página ou qualquer tecla para voltar: ");
        scanf(" %c", &continuar);
        if (continuar == 'n') {
            pagina++;
            if (pagina * LIVROS_POR_PAGINA >= numLivros) pagina = 0;
        } else {
            break;
        }
    } while (1);
}

void emprestarLivro() {
    printf("\nLivros Disponíveis para Empréstimo:\n");
    for (int i = 0; i < numLivros; i++) {
        int disponiveis = biblioteca[i].estoque - biblioteca[i].emprestados;
        if (disponiveis > 0) {
            printf("%d - %s (%d disponíveis)\n", i, biblioteca[i].titulo, disponiveis);
        }
    }

    int idx;
    printf("Escolha o número do livro para emprestar: ");
    scanf("%d", &idx);

    if (idx >= 0 && idx < numLivros) {
        int disponiveis = biblioteca[idx].estoque - biblioteca[idx].emprestados;
        if (disponiveis > 0) {
            biblioteca[idx].emprestados++;
            printf("Empréstimo realizado com sucesso!\n");
        } else {
            printf("Este livro está com todos os exemplares emprestados!\n");
        }
    } else {
        printf("Opção inválida!\n");
    }
}

void devolverLivro() {
    printf("\nLivros para Devolução:\n");
    for (int i = 0; i < numLivros; i++) {
        if (biblioteca[i].emprestados > 0) {
            printf("%d - %s (%d emprestados)\n", i, biblioteca[i].titulo, biblioteca[i].emprestados);
        }
    }
    int idx, qtd;
    printf("Escolha o número do livro para devolver: ");
    scanf("%d", &idx);

    if (idx >= 0 && idx < numLivros && biblioteca[idx].emprestados > 0) {
        printf("Quantos deseja devolver? ");
        scanf("%d", &qtd);

        if (qtd > 0 && qtd <= biblioteca[idx].emprestados) {
            biblioteca[idx].emprestados -= qtd;
            printf("Devolução realizada com sucesso!\n");
        } else {
            printf("Quantidade inválida!\n");
        }
    } else {
        printf("Opção inválida!\n");
    }
}

void adicionarLivro() {
    if (numLivros >= MAX_LIVROS) {
        printf("Biblioteca cheia!\n");
        return;
    }
    Livro novoLivro;
    printf("Digite o título: ");
    getchar();
    fgets(novoLivro.titulo, sizeof(novoLivro.titulo), stdin);
    strtok(novoLivro.titulo, "\n");
    printf("Digite o autor: ");
    fgets(novoLivro.autor, sizeof(novoLivro.autor), stdin);
    strtok(novoLivro.autor, "\n");
    printf("Digite o gênero: ");
    fgets(novoLivro.genero, sizeof(novoLivro.genero), stdin);
    strtok(novoLivro.genero, "\n");
    printf("Digite a sinopse: ");
    fgets(novoLivro.sinopse, sizeof(novoLivro.sinopse), stdin);
    strtok(novoLivro.sinopse, "\n");
    printf("Digite a quantidade de exemplares: ");
    scanf("%d", &novoLivro.estoque);
    novoLivro.emprestados = 0;
    biblioteca[numLivros++] = novoLivro;
    printf("Livro adicionado com sucesso!\n");
}

void alterarLivro() {
    listarLivrosPaginado();
    int idx;
    printf("Escolha o número do livro para alterar: ");
    scanf("%d", &idx);
    getchar();
    if (idx >= 0 && idx < numLivros) {
        printf("Novo título: ");
        fgets(biblioteca[idx].titulo, sizeof(biblioteca[idx].titulo), stdin);
        strtok(biblioteca[idx].titulo, "\n");
        printf("Novo autor: ");
        fgets(biblioteca[idx].autor, sizeof(biblioteca[idx].autor), stdin);
        strtok(biblioteca[idx].autor, "\n");
        printf("Novo gênero: ");
        fgets(biblioteca[idx].genero, sizeof(biblioteca[idx].genero), stdin);
        strtok(biblioteca[idx].genero, "\n");
        printf("Nova sinopse: ");
        fgets(biblioteca[idx].sinopse, sizeof(biblioteca[idx].sinopse), stdin);
        strtok(biblioteca[idx].sinopse, "\n");
        printf("Alteração realizada com sucesso!\n");
    } else {
        printf("Opção inválida!\n");
    }
}

void excluirLivro() {
    listarLivrosPaginado();
    int idx;
    printf("Escolha o número do livro para excluir: ");
    scanf("%d", &idx);
    if (idx >= 0 && idx < numLivros) {
        for (int i = idx; i < numLivros - 1; i++) {
            biblioteca[i] = biblioteca[i + 1];
        }
        numLivros--;
        printf("Livro excluído com sucesso!\n");
    } else {
        printf("Opção inválida!\n");
    }
}

int main() {
    int opcao;
    do {
        limparTela();
        printf("\nMENU:\n");
        printf("1 - Procurar Exemplar\n");
        printf("2 - Empréstimo\n");
        printf("3 - Devolução\n");
        printf("4 - Adicionar Livro\n");
        printf("5 - Alterar Livro\n");
        printf("6 - Excluir Livro\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch (opcao) {
            case 1:
                listarLivrosPaginado();
                break;
            case 2:
                emprestarLivro();
                break;
            case 3:
                devolverLivro();
                break;
            case 4:
                adicionarLivro();
                break;
            case 5:
                alterarLivro();
                break;
            case 6:
                excluirLivro();
                break;
        }
    } while (opcao != 0);
    printf("Saindo...\n");
    return 0;
}
