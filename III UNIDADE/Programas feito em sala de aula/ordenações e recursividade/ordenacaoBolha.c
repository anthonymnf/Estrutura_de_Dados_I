#include <stdio.h>
#include <stdlib.h>

struct Aluno
{
  int mat;
  char nome[30];
  float media;
};

typedef struct Aluno Aluno;

void ordenacaoBolha(Aluno *v, int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (v[j].mat > v[j + 1].mat)
      {
        Aluno temp = v[j];
        v[j] = v[j + 1];
        v[j + 1] = temp;
      }
    }
  }
}

int main()
{
  int n;
  printf("Quantidade de itens: ");
  scanf("%d", &n);
  fflush(stdin);
  Aluno *vet;
  vet = (Aluno *)malloc(n * sizeof(Aluno));
  printf("Informe os dados na ordem: Matricula, media e nome\n");
  for (int p = 0; p < n; p++)
  {
    scanf("%d", &vet[p].mat);
    fflush(stdin);
    scanf("%f", &vet[p].media);
    fflush(stdin);
    scanf("%s", vet[p].nome);
    fflush(stdin);
  }
  ordenacaoBolha(vet, n);
  printf("\nVetor ordenado: \n");
  for (int k = 0; k < n; k++)
  {
    printf("Nome: %s\n", vet[k].nome);
    printf("Matricula: %d\n", vet[k].mat);
    printf("Media: %.2f\n", vet[k].media);
  }
  return 0;
}
