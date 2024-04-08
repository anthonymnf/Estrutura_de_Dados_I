#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int mat;
    char nome[50];
    float media;
} Estudante;

struct no
{
    Estudante dado;
    struct no *prox;
};

typedef struct no No;

typedef struct
{
    No *inicio;
} Lista;

void adicionaFim(Lista *lista, Estudante e)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = e;
    novo->prox = NULL;
    if (lista->inicio == NULL)
    {
        lista->inicio = novo;
    }
    else
    {
        No *pi;
        for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox)
            ;
        pi->prox = novo;
    }
}

void mostrar(Lista lista)
{
    No *pi;
    for (pi = lista.inicio; pi != NULL; pi = pi->prox)
    {
        Estudante dado = pi->dado;
        printf("%d %s %f\n", dado.mat, dado.nome, dado.media);
    }
}

void ler(Estudante *e)
{
    printf("Informe os dados do estudante:\n");
    scanf("%d %s %f", &e->mat, e->nome, &e->media);
}

void editarMedia(Lista *lista, int mat, float media)
{
    if (lista->inicio == NULL)
    {
        printf("Lista Vazia\n");
    }
    else
    {
        No *pi;
        for (pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox)
            ;
        if (pi == NULL)
        {
            printf("Aluno nao encontrado\n");
        }
        else
        {
            pi->dado.media = media;
            printf("Media atualizada!\n");
        }
    }
}
void deletar(Lista *lista, int mat)
{
    if (lista->inicio == NULL)
    {
        printf("Lista Vazia\n");
    }
    else
    {
        No *pi, *pa = NULL;
        for (pi = lista->inicio; pi != NULL && pi->dado.mat != mat; pi = pi->prox)
        {
            pa = pi;
        }
        if (pa == NULL)
        {
            if (pi->dado.mat == mat)
            {
                lista->inicio = pi->prox;
                free(pi);
            }
            else
            {
                printf("Aluno não encontrado\n");
            }
        }
        else
        {
            pa->prox = pi->prox;
            printf("Aluno deletado\n");
            free(pi);
        }
    }
}

void menu()
{
    printf("=== escolha uma opcao ===\n");
    printf("1 - inserir\n");
    printf("2 - mostrar\n");
    printf("3 - editar media\n");
    printf("4 - deletar\n");
    printf("0 - sair\n");
    printf("=========================\n");
}

int main()
{
    Lista lista;
    lista.inicio = NULL;
    int op;
    menu();
    scanf("%d", &op);
    while (op != 0)
    {
        if (op == 1)
        {
            Estudante e;
            ler(&e);
            adicionaFim(&lista, e);
        }
        else if (op == 2)
        {
            mostrar(lista);
        }
        else if (op == 3)
        {
            int mat;
            float media;
            printf("Informe a matricula e a media:\n");
            scanf("%d %f", &mat, &media);
            editarMedia(&lista, mat, media);
        }
        else if (op == 4)
        {
            int mat;
            printf("Informe a matricula:\n");
            scanf("%d", &mat);
            deletar(&lista, mat);
        }
        menu();
        scanf("%d", &op);
    }
}