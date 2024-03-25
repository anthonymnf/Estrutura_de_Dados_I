#include <stdio.h>
#include <stdlib.h>

void intercala(int vet1[], int vet2[], int tam, int vet3[])
{
  int iV1 = 0, iV2 = 0;
  for (int i = 0; i < tam; i++)
  {
    if (vet1[iV1] < vet2[iV2])
    {
      vet3[i] = vet1[iV1];
      iV1++;
    }
    else
    {
      vet3[i] = vet2[iV2];
      iV2++;
    }
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
  intercala(vet1, vet2, tam, vet3);
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
