#include <stdio.h>

struct Aluno
{
  int mat;
  char nome[30];
  float media;
};

typedef struct Aluno Aluno;

void insertionSort(Aluno v[], int n)
{
  int j;
  for (int i = 1; i < n; i++)
  {
    Aluno x = v[i];
    for (j = i - 1; j >= 0 && x.media < v[j].media; j--)
    {
      v[j + 1] = v[j];
    }
    v[j + 1] = x;
  }
  printf("Ordenado:\n");
  for (int k = 0; k < n; k++)
  {
    printf("%s: %.2f\n", v[k].nome, v[k].media);
  }
}

int main()
{
  int n, j;
  printf("Informe a qunatidade de alunos:\n");
  scanf("%d", &n);
  Aluno v[n];
  printf("Informe o vetor:\n");
  for (j = 0; j < n; j++)
  {
    scanf("%d %s %f", &v[j].mat, v[j].nome, &v[j].media);
  }
  insertionSort(v, n);

  return 0;
}
