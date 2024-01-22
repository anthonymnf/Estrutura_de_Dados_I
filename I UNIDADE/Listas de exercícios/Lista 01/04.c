#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ingrediente
{
  char nomeIngrediente[50];
  int qnt;
};

typedef struct ingrediente ingrediente;

struct receita
{
  char nome[25];
  int qntIngredientes;
  ingrediente *ingredientes;
};

typedef struct receita receita;

int main()
{
  receita receitas[5];
  // ler dados
  for (int i = 0; i < 5; i++)
  {
    printf("Qual o nome da receita?\n");
    gets(receitas[i].nome);
    fflush(stdin);
    printf("Qual a quantidade de ingredientes?\n");
    scanf("%i", &receitas[i].qntIngredientes);
    fflush(stdin);
    // Alocação dinâmica para o vetor de ingredientes
    receitas[i].ingredientes = (ingrediente *)malloc(receitas[i].qntIngredientes * sizeof(ingrediente));
    for (int j = 0; j < receitas[i].qntIngredientes; j++)
    {
      printf("\nQual o nome do ingrediente?\n");
      gets(receitas[i].ingredientes[j].nomeIngrediente);
      fflush(stdin);
      printf("Qual a quantidade desse ingrediente?\n");
      scanf("%i", &receitas[i].ingredientes[j].qnt);
      fflush(stdin);
    }
  }
  // exibir dados
  for (int i = 0; i < 5; i++)
  {
    printf("\nReceita %d\n", i + 1);
    printf("Nome: %s \n", receitas[i].nome);
    printf("Quantidade de ingredientes: %i\n", receitas[i].qntIngredientes);
    for (int j = 0; j < receitas[i].qntIngredientes; j++)
    {
      printf("- Ingrediente: %s", receitas[i].ingredientes[j].nomeIngrediente);
      printf("\n- Quantidade: %i", receitas[i].ingredientes[j].qnt);
      printf("\n-------------------\n");
    }
    // Liberar a memória alocada para o vetor de ingredientes
    free(receitas[i].ingredientes);
  }

  return 0;
}
