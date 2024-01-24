#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Escrever um programa que cadastre produtos. Para cada produto devem
// conter seguintes dados: nome, código, preço e quantidade do produto.
// • Adicione 5 produtos à loja.
// • Imprima uma lista com o código e nome de cada produto.
// • Leia um valor x e mostre as informações de todos os produtos com o
// preço menor que x.

struct Produto
{
  char nome[20];
  int codigo;
  float preco;
  int qntd;
};

typedef struct Produto Produto;

int main()
{
  Produto produtos[5];
  // Adicionando produtos
  for (int i = 0; i < 5; i++)
  {
    printf("Informe:\n");
    printf("-Nome: ");
    gets(produtos[i].nome);
    fflush(stdin); // Limpando lixo do teclado, pra avitar bug
    printf("-Codigo: ");
    scanf("%i", &produtos[i].codigo);
    fflush(stdin);
    printf("-Preco: ");
    scanf("%f", &produtos[i].preco);
    fflush(stdin);
    printf("-Quantidade: ");
    scanf("%i", &produtos[i].qntd);
    fflush(stdin);
  }
  // Imprimindo lista de produtos
  for (int i = 0; i < 5; i++)
  {
    printf("Produto %i:", i + 1);

    printf("\n- Nome: %s", produtos[i].nome);
    printf("\n- Codigo: %i", produtos[i].codigo);
    printf("\n----------------------------\n");
  }

  // Último item do enunciado:
  float x;
  printf("Informe um preco X: ");
  scanf("%f", &x);

  for (int i = 0; i < 5; i++)
  {
    if (produtos[i].preco < x)
    {
      printf("Produto %i:", i + 1);
      printf("\n- Nome: %s", produtos[i].nome);
      printf("\n- Codigo: %i", produtos[i].codigo);
      printf("\n- Preso: %.2f", produtos[i].preco);
      printf("\n- Quantidade: %i", produtos[i].qntd);
      printf("\n----------------------------\n");
    }
  }

  return 0;
}
