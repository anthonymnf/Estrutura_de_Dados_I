#include <stdio.h>
#include <stdlib.h>

// A versão 1 na minha opinião está melhor

void intercala(int v1[], int n, int v2[], int m, int v3[])
{
  int i = 0, j = 0, k = 0;
  while (i < n && j < m)
  {
    if (v1[i] < v2[j])
    {
      v3[k] = v1[i];
      i++;
    }
    else
    {
      v3[k] = v2[j];
      j++;
    }
    k++;
  }
  while (i < n)
  {
    v3[k] = v1[i];
    i++;
    k++;
  }
  while (j < m)
  {
    v3[k] = v2[j];
    j++;
    k++;
  }
}

int main()
{
  int n, n2;
  printf("Tamanho do vetor 1: ");
  scanf("%d", &n);
  int *vet1;
  vet1 = (int *)malloc(n * sizeof(int));
  printf("Informe os valores do vetor 1:\n");
  for (int p = 0; p < n; p++)
  {
    scanf("%d", &vet1[p]);
  }
  printf("Tamanho do vetor 2: ");
  scanf("%d", &n2);
  int *vet2;
  vet2 = (int *)malloc(n2 * sizeof(int));
  printf("Informe os valores do vetor 2:\n");
  for (int p = 0; p < n2; p++)
  {
    scanf("%d", &vet2[p]);
  }
  int *vet3;
  int tam = n + n2;
  vet3 = (int *)malloc(tam * sizeof(int));
  intercala(vet1, n, vet2, n2, vet3);
  printf("\nVetor ordenado: [ ");
  for (int k = 0; k < tam; k++)
  {
    printf("%d ", vet3[k]);
  }
  printf("]");
  free(vet1);
  free(vet2);
  free(vet3);
  return 0;
}
