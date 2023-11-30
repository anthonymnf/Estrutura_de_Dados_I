// Treinando o uso de structs
#include <stdio.h>

struct Data
{
  int dia;
  char mes[20];
  int ano;
};

struct Candidatos
{
  char nome[50];
  char endereco[50];
  char partido[50];
  char cargo[50];
  int numero_de_votos;
  struct Data data_da_eleicao;
};

int main()
{
  int QntCand = 1; // Define a quantidade de candidatos nessa eleição
  struct Candidatos candidatos_vet[QntCand];
  // Lendo dados
  for (int i = 0; i < QntCand; i++)
  {
    printf("Digite as informações do candidato, na seginte ordem:\nNome,Endereço, Partido,Cargo, Número de votos, dia, mes e ano da eleição\n");
    scanf("%49[^\n]", candidatos_vet[i].nome);
    fflush(stdin);
    scanf("%49[^\n]", candidatos_vet[i].endereco);
    fflush(stdin);
    scanf("%49[^\n]", candidatos_vet[i].partido);
    fflush(stdin);
    scanf("%49[^\n]", candidatos_vet[i].cargo);
    fflush(stdin);
    scanf("%i", &candidatos_vet[i].numero_de_votos);
    fflush(stdin);
    scanf("%i", &candidatos_vet[i].data_da_eleicao.dia);
    fflush(stdin);
    scanf("%19[^\n]", candidatos_vet[i].data_da_eleicao.mes);
    fflush(stdin);
    scanf("%i", &candidatos_vet[i].data_da_eleicao.ano);
    fflush(stdin);
  }
  // Exibindo dados
  for (int i = 0; i < QntCand; i++)
  {
    printf("Os dados do candidato são:\n");
    printf("Nome: %s\n", candidatos_vet[i].nome);
    printf("Endereço: %s\n", candidatos_vet[i].endereco);
    printf("Partido: %s\n", candidatos_vet[i].partido);
    printf("Cargo: %s\n", candidatos_vet[i].cargo);
    printf("Votos: %i\n", candidatos_vet[i].numero_de_votos);
    printf("O dia da eleição é: %i/%s/%i\n", candidatos_vet[i].data_da_eleicao.dia, candidatos_vet[i].data_da_eleicao.mes, candidatos_vet[i].data_da_eleicao.ano);
  }

  return 0;
}
