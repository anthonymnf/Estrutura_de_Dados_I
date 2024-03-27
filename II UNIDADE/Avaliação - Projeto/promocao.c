#include <stdio.h>
#include <stdlib.h>
struct Remedio
{
  int codigo;
  char nome[30];
  float preco;
  int estoque;
};

typedef struct Remedio Remedio;
// Função responsável por cadastrar remédios em promoçaõ no arquivo promocao.b
void cadastrarPromocao()
{
  FILE *file = fopen("promocao.b", "ab");
  int a;
  printf("Informe o codigo do remedio em promocao:\n");
  scanf("%d", &a);
  fwrite(&a, sizeof(int), 1, file);
  fclose(file);
}

// Função responsável por buscar remédios em pharma.b
void buscar(int cod)
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int entrou = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    if (a.codigo == cod)
    {
      printf("\nNome: %s\n", a.nome);
      printf("- Codigo: %d\n", a.codigo);
      printf("- Preco: %.2f\n", a.preco);
      printf("- Quantidade em estoque: %d\n", a.estoque);
      entrou = 1;
    }
  }
  if (entrou == 0)
  {
    printf("Remedio nao encontrado\n");
  }
  fclose(file);
}

// Função responsável por cadastrar remédios em promoçaõ no arquivo promocao.b
void buscarPromocao()
{
  FILE *file = fopen("promocao.b", "rb");
  int a;
  printf("Remedios em promocao:\n");
  while (fread(&a, sizeof(int), 1, file))
  {
    buscar(a);
  }
  fclose(file);
}

int main()
{
  int op;
  scanf("%d", &op);
  if (op == 1)
  {
    cadastrarPromocao();
  }
  else
  {
    printf("Chegou");
    buscarPromocao();
  }

  return 0;
}
