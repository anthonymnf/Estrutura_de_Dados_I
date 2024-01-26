#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno
{
  char nome[30];
  float media;
  int faltas;
};

typedef struct Aluno Aluno;

int compararMedias(const void *a, const void *b)
{
  return (((Aluno *)a)->media - ((Aluno *)b)->media);
}

int main()
{
  int n;
  Aluno *alunos;
  printf("Quantos alunuos serao cadastrados?\n");
  scanf("%i", &n);
  alunos = (Aluno *)malloc(n * sizeof(Aluno));
  printf("Informe:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Aluno %i\n", i + 1);
    fflush(stdin);
    printf("-Nome: ");
    gets(alunos[i].nome);
    fflush(stdin);
    printf("-Media: ");
    scanf("%f", &alunos[i].media);
    fflush(stdin);
    printf("-Faltas: ");
    scanf("%i", &alunos[i].faltas);
    printf("\n");
  }
  printf("Alunos em ordem decrescente pela media:\n");
  qsort(alunos, n, sizeof(Aluno), compararMedias);
  for (int i = n - 1; i > -1; i--)
  {
    printf("Aluno: %s\n", alunos[i].nome);
    printf("Media: %.2f\n", alunos[i].media);
    printf("Faltas: %i\n", alunos[i].faltas);
    printf("------------------------\n");
  }

  free(alunos);

  return 0;
}
