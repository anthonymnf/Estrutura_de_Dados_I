#include <stdio.h>

// Projeto de um sistema de fármacia (EM CONSTRUÇÃO)

// Funções pra se adicionar:
// - Login;
// - Modo cliente e admin;
//   No modo admin terá: cadastrar, listar, editar e excluir
//   No modo cliente terá: Simulação de comprar, listar produtos, ver produtos com um preço abaixo de um valor x. Na simulação de compra diminuir a quantidade de estoque, buscar por um remédio em específico;
// - Ordenar produtos por preço (Opcional)

typedef struct
{
  int mat;
  char nome[10];
  float media;
} aluno;

struct Remedio
{
  int codigo;
  char nome[30];
  float preco;
  int estoque;
};

typedef struct Remedio Remedio;

// Esse será o menu e opções do modo admin
void menu()
{
  printf("Escolha uma opcao:\n");
  printf("1 - Cadastar remedio\n");
  printf("2 - Listar remedios\n");
  printf("3 - Buscar remedio\n");
  printf("4 - Quantidade de alunos\n");
  printf("5 - Excluir um remedio\n");
  printf("6 - Editar um aluno\n");
  printf("0 - Sair\n");
  printf("===================\n");
}

// Adaptação Concluida
void cadastrar()
{
  FILE *file = fopen("pharma.b", "ab");
  Remedio a;
  printf("Informe os dados do remedio:\n");
  scanf("%d %s %f %d", &a.codigo, a.nome, &a.preco, &a.estoque);
  fwrite(&a, sizeof(Remedio), 1, file);
  fclose(file);
}

// Adaptação Concluida
void buscar(int cod)
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int entrou = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    if (a.codigo == cod)
    {
      printf("%d: %s %f\n", a.codigo, a.nome, a.preco);
      printf("- Preco: %d\n", a.preco);
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

// Adaptação Concluida
void listar()
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  while (fread(&a, sizeof(aluno), 1, file))
  {
    printf("%d: %s %f\n", a.codigo, a.nome, a.preco);
    printf("- Preco: %d\n", a.preco);
    printf("- Quantidade em estoque: %d\n", a.estoque);
  }
  fclose(file);
}

// Adaptação Concluida
int tamanho()
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int cont = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    cont++;
  }
  fclose(file);
  return cont;
}

// Adaptação Concluida
void excluir(int cod)
{
  int n = tamanho();
  Remedio v[n];
  FILE *file = fopen("pharma.b", "rb");
  int i = 0;
  while (fread(&v[i], sizeof(Remedio), 1, file))
  {
    i++;
  }
  fclose(file);
  file = fopen("pharma.b", "wb");
  for (i = 0; i < n; i++)
  {
    if (v[i].codigo != cod)
    {
      fwrite(&v[i], sizeof(Remedio), 1, file);
    }
  }
  fclose(file);
}

// Adicionar a opção de escolher oque editar e tratar essa opções
// Podemos editar preço e quantidade em estoque

void editar(int cod)
{
  int n = tamanho();
  Remedio v[n];
  FILE *file = fopen("pharma.b", "rb");
  int i = 0;
  while (fread(&v[i], sizeof(Remedio), 1, file))
  {
    i++;
  }
  fclose(file);
  file = fopen("pharma.b", "wb");
  for (i = 0; i < n; i++)
  {
    if (v[i].codigo == cod)
    {
      // float media;
      // printf("Informe a nota nota:\n");
      // scanf("%f", &media);
      // v[i].media = media;
      // printf("media: %f", media);
    }
    // printf("media: %f", v[i].media);
    // fwrite(&v[i], sizeof(aluno), 1, file);
  }
  fclose(file);
}

int main()
{
  int op;
  menu();
  scanf("%d", &op);
  while (op != 0)
  {
    if (op == 1)
    {
      cadastrar();
    }
    else if (op == 2)
    {
      listar();
    }
    else if (op == 3)
    {
      int cod;
      printf("Informe o codigo do produto:\n");
      scanf("%d", &cod);
      buscar(cod);
    }
    else if (op == 4)
    {
      int n = tamanho();
      printf("Quantidade de remedios na farmacia: %d\n", n);
    }
    else if (op == 5)
    {
      int cod;
      printf("Informe o codigo do remedio que voce deseja excluir:\n");
      scanf("%d", &cod);
      excluir(cod);
    }
    else if (op == 6)
    {
      int cod;
      printf("Informe o codigo do remedio que voce deseja excluir:\n");
      scanf("%d", &cod);
      editar(cod);
    }
    menu();
    scanf("%d", &op);
  }
  return 0;
}