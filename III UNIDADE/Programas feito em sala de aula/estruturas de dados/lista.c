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
      pi->prox = novo;
  }
}

void mostrar(Lista lista)
{
  No *pi;
  printf("entrou");
  int count = 1;
  for (pi = lista.inicio; pi->prox != NULL; pi = pi->prox)
  {
    Estudante dado = pi->dado;
    printf("Aluno %d\n:", count);
    printf("- Nome: %s\n", dado.nome);
    printf("- Matricula: %d\n", dado.mat);
    printf("- Media: %.2f\n", dado.media);
    count++;
  }
}

void ler(Estudante *e)
{
  printf("Informe os dados na ordem: matricula, nome, e media\n");
  scanf("%d %s %f", &e->mat, e->nome, &e->media);
}

void menu()
{
  printf("\nEscolha uma opcao\n");
  printf("1 - Inserir\n2 - Mostrar\n0 - Sair\n");
  printf("-------------------------\n");
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
    menu();
    scanf("%d", &op);
  }

  return 0;
}
