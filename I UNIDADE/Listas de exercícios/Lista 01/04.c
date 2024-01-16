#include <stdio.h>
#include <string.h>

struct ingrediente
{
  char nomeIngrediente[20];
  int qnt;
};

typedef struct ingrediente ingrediente;

struct receita
{
  char nome[25];
  int qntIngredientes;
  ingrediente ingredientes[20];
};

typedef struct receita receita;

int main()
{
  receita receitas[2];
  // ler dados
  for (int i = 0; i < 2; i++)
  {
    printf("Qual o nome da receita?\n");
    gets(receitas[i].nome);
    fflush(stdin);
    printf("Qual a quantidade de ingredientes?\n");
    scanf("%i", &receitas[i].qntIngredientes);
    fflush(stdin);
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
  for (int i = 0; i < 2; i++)
  {
    printf("Nome: %s \n", receitas[i].nome);
    printf("Quantidade de ingredientes: %i\n", receitas[i].qntIngredientes);
    for (int j = 0; j < receitas[i].qntIngredientes; j++)
    {
      printf("- Ingrediente: %s", receitas[i].ingredientes[j].nomeIngrediente);
      printf("\n- Quantidade: %i", receitas[i].ingredientes[j].qnt);
      printf("\n-------------------\n");
    }
  }

  return 0;
}
