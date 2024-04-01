#include <stdio.h>
#include <stdlib.h>

void intercala(int e, int m, int d, int v[])
{
  int n1 = (m - e) + 1;
  int n2 = (d - m);
  int E[n1];
  int D[n2];
  int i, j;
  // Preenchendo os vetores E e D
  for (i = 0; i < n1; i++)
  {
    E[i] = v[e + i];
  }
  for (j = 0; j < n2; j++)
  {
    D[j] = v[m + 1 + j];
  }

  // Parte responsável por ordenar
  i = 0;
  j = 0;
  int k = e;
  while (i < n1 && j < n2)
  {
    if (E[i] < D[j])
    {
      v[k] = E[i];
      i++;
    }
    else
    {
      v[k] = D[j];
      j++;
    }
    k++;
  }
  // Nessa parte jogamos os dados que sobraram no vetor resultante
  while (i < n1)
  {
    v[k] = E[i];
    i++;
    k++;
  }
  while (j < n2)
  {
    v[k] = D[j];
    j++;
    k++;
  }
}
// Função responsável por juntar as partes ordenadas
void mergeSort(int i, int f, int v[])
{
  if (i < f)
  {
    int meio = (i + f) / 2;
    mergeSort(i, meio, v);
    mergeSort(meio + 1, f, v);
    intercala(i, meio, f, v);
  }
}

int main()
{
  int n;
  printf("Tamanho do vetor: ");
  scanf("%d", &n);
  int *vet1;
  vet1 = (int *)malloc(n * sizeof(int));
  printf("Informe os valores do vetor:\n");
  for (int p = 0; p < n; p++)
  {
    scanf("%d", &vet1[p]);
  }

  mergeSort(0, n - 1, vet1);
  printf("\nVetor ordenado: [ ");
  for (int k = 0; k < n; k++)
  {
    printf("%d ", vet1[k]);
  }
  printf("]");
  free(vet1);
  return 0;
}
