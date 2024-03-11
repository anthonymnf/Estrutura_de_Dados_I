#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  printf("Quantidade de itens: ");
  scanf("%d", &n);
  int *vet;
  vet = (int *)malloc(n * sizeof(int));
  for (int p = 0; p < n; p++)
  {
    scanf("%d", &vet[p]);
  }

  for (int i = 0; i < n; i++)
  {
    int imenor = i;
    for (int j = i + 1; j < n; j++)
    {
      if (vet[j] < vet[imenor])
      {
        imenor = j;
      }
    }
    int temp = vet[i];
    vet[i] = vet[imenor];
    vet[imenor] = temp;
  }

  printf("\nVetor ordenado: [ ");
  for (int k = 0; k < n; k++)
  {
    printf("%d ", vet[k]);
  }
  printf("]");

  return 0;
}
