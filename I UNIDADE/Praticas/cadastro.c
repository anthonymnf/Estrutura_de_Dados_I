#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Endereco
{
  char rua[30];
  char bairro[30];
  char cidade[30];
};

struct Cadastro
{
  char nome[30];
  float salario;
  int idade;
  struct Endereco endereco;
};

typedef struct Cadastro Cadastro;

int main()
{
  Cadastro *pessoas;
  int quant, maiorIdade = 0, idMaiorIdade;
  printf("Informe quantas pessoas serao cadastradas: ");
  scanf("%i", &quant);
  fflush(stdin);
  pessoas = (Cadastro *)malloc(quant * sizeof(Cadastro));
  printf("Informe os seguintes dados: \n");
  for (int i = 0; i < quant; i++)
  {
    printf("-Nome: ");
    gets(pessoas[i].nome); // Não precisa de & pois é uma string, pros demais tipos precisa
    fflush(stdin);
    printf("-Salario: ");
    scanf("%f", &pessoas[i].salario);
    printf("-Idade: ");
    scanf("%i", &pessoas[i].idade);
    fflush(stdin);
    printf("-Rua: ");
    gets(pessoas[i].endereco.rua);
    fflush(stdin);
    printf("-Bairro: ");
    gets(pessoas[i].endereco.bairro);
    fflush(stdin);
    printf("-Cidade: ");
    gets(pessoas[i].endereco.cidade);
    fflush(stdin);
    if (pessoas[i].idade > maiorIdade)
    {
      maiorIdade = pessoas[i].idade;
      idMaiorIdade = i;
    }
  }
  printf("\nA pessoas com a maior idade e %s com %i anos.\n", pessoas[idMaiorIdade].nome, maiorIdade);
  printf("- Pessoas com salarios maiores que R$2000: \n");
  for (int i = 0; i < quant; i++)
  {
    if (pessoas[i].salario > 2000)
    {
      printf("- Nome: %s e salario %.2f\n", pessoas[i].nome, pessoas[i].salario);
    }
  }

  free(pessoas);
  return 0;
}
