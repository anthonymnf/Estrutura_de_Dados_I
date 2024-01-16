#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dadosPessoais
{
  char nome[50];
  char endereco[50];
  int telefone;
};
typedef struct dadosPessoais dados;

// Função de comparação para qsort
int compararPessoas(const void *a, const void *b)
{
  return strcmp(((dados *)a)->nome, ((dados *)b)->nome);
}

// Função para imprimir dados em ordem alfabética
void imprimirEmOrdemAlfabetica(dados pessoas[], int tamanho)
{
  // Ordena o array usando qsort
  qsort(pessoas, tamanho, sizeof(dados), compararPessoas);
  printf("-------------------------\n");
  printf("Dados ordenados: \n");
  // Imprime os dados ordenados
  for (int i = 0; i < tamanho; i++)
  {
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Endereco: %s\n", pessoas[i].endereco);
    printf("Telefone: %i\n", pessoas[i].telefone);
    printf("\n");
  }
}

int main()
{
  dados pessoas[5];

  // Pegando os dados
  for (int i = 0; i < 5; i++)
  {
    printf("Insira seus dados pessoais:\n");
    printf("-Nome: ");
    gets(pessoas[i].nome);
    fflush(stdin);
    printf("-Endereco: ");
    gets(pessoas[i].endereco);
    fflush(stdin);
    printf("-Numero de telefone: ");
    scanf("%i", &pessoas[i].telefone);
    fflush(stdin);
  }

  // Imprime os dados em ordem alfabética
  imprimirEmOrdemAlfabetica(pessoas, 5);

  return 0;
}
