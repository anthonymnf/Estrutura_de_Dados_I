#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
  int matricula;
  char nome[30];
  float media;
};

typedef struct Aluno Aluno;

int buscaBinaria(Aluno v[], int n, int matricula)
{
  int inicio = 0, fim = n - 1;
  while (inicio <= fim)
  {
    int meio = (inicio + fim) / 2;
    if (v[meio].matricula == matricula)
    {
      return meio;
    }
    else if (v[meio].matricula < matricula)
    {
      inicio = meio + 1;
    }
    else
    {
      fim = meio - 1;
    }
  }
  return -1;
}

int main()
{
  int n;
  printf("Informe a quantidade de alunos: ");
  scanf("%d", &n);
  Aluno *alunos;
  alunos = (Aluno *)malloc(n * sizeof(Aluno));
  printf("Informe os dados dos alunos: \n");
  for (int i = 0; i < n; i++)
  {
    scanf("%d %s %f", &alunos[i].matricula, alunos[i].nome, &alunos[i].media);
  }
  printf("Informe a matricula: ");
  int mat;
  scanf("%d", &mat);
  int result = buscaBinaria(alunos, n, mat);
  if (result != -1)
  {
    printf("Aluno: %s\n", alunos[result].nome);
  }
  else
  {
    printf("Aluno não encontrado\n");
  }

  return 0;
}
