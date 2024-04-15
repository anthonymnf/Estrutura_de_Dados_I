#include <stdio.h>
#include <stdlib.h>
#include "estudante.h"

struct estudante
{
  int mat;
  char nome[50];
  float media;
};

Estudante *criaLista(int n)
{
  Estudante *v = (Estudante *)malloc(n * sizeof(Estudante));
  return v;
}

void lerEstudantes(int n, Estudante *v)
{
  printf("Informe os dados dos estudantes, na ordem: Matricula Nome Media\n");
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Informe os dados do estudante %d:\n", i + 1);
    scanf("%d %s %f", &v[i].mat, v[i].nome, &v[i].media);
  }
}

void imprimeEstudantes(int n, Estudante *v)
{
  printf("Imprimindo estudantes:\n");
  int i;
  for (i = 0; i < n; i++)
  {
    printf("%d %s %f\n", v[i].mat, v[i].nome, v[i].media);
  }
}