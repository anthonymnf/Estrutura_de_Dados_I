#include <stdio.h>
#include <stdlib.h>
// Este projeto é uma melhoria do anterior, não foi passado pelo professor,
// mas eu quis dar um melhorada e aplicar outros conceitos

// Este projeto está incompleto, passos que restam pra fazer:
//  - Terminar função cadastrar
//  - Modificar função listar para apresentar os demais dados

struct item
{
  char nome[30];
  int codigo;
  int quant;
};

struct Cliente
{
  char nome[30];
  float compra;
  struct item *itens;
};

typedef struct Cliente Cliente;

void menu()
{
  printf("Escolha uma opcao:\n");
  printf("1-Cadastrar\n2-Listar\n3-Sair\n");
  printf("-----------------------\n");
}

void cadastrar()
{
  int qnt;
  FILE *file = fopen("cliente.b", "ab");
  printf("Informe o nome e o valor da compra:\n");
  Cliente cliente;
  scanf("%s %f", cliente.nome, &cliente.compra);
  printf("Informe a quantidade de produtos:");
  scanf("%d", &qnt);
  cliente.itens = (struct item *)malloc(sizeof(struct item) * qnt);
  for (int i = 0; i < qnt; i++)
  {
    printf("Informe o nome, codigo e qunatidade do produto:\n");
    scanf("%s %i %i", cliente.itens->nome, &cliente.itens->codigo, &cliente.itens->quant);
    // Continuaaaaaaa
  }

  fwrite(&cliente, sizeof(Cliente), 1, file);
  fclose(file);
}

void listar()
{
  FILE *file = fopen("cliente.b", "rb");
  Cliente cliente;
  printf("\nBanco de dados:\n");
  while (fread(&cliente, sizeof(Cliente), 1, file))
  {
    printf("%s: %.2f\n", cliente.nome, cliente.compra);
  }
  printf("\n");
  fclose(file);
}

int main()
{
  int op;
  menu();

  scanf("%d", &op);
  while (op != 3)
  {
    if (op == 1)
    {
      cadastrar();
    }
    else if (op == 2)
    {
      listar();
    }
    menu();
    scanf("%d", &op);
  }

  return 0;
}