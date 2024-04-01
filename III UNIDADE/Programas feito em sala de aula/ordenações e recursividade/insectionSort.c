#include <stdio.h>
// Insection sort

int main()
{
  int n, j;
  printf("Informe o valor de n: ");
  scanf("%d", &n);
  int v[n];
  printf("Informe o vetor:\n");
  for (j = 0; j < n; j++)
  {
    scanf("%d", &v[j]);
  }
  for (int i = 1; i < n; i++)
  {
    int x = v[i];
    for (j = i - 1; j >= 0 && x < v[j]; j--)
    {
      v[j + 1] = v[j];
    }
    v[j + 1] = x;
  }

  printf("\nVetor ordenado: [ ");
  for (int k = 0; k < n; k++)
  {
    printf("%d ", v[k]);
  }
  printf("]");
  return 0;
}