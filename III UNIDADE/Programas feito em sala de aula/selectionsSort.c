#include <stdio.h>
// Insere o número na possição correspondente dele em ordem crescente
//  Selection sort

int main()
{
  int n, j, x;
  printf("Informe o valor de n: ");
  scanf("%d", &n);
  int v[n + 1];
  printf("Informe o vetor em ordem crescente:\n");
  for (j = 0; j < n; j++)
  {
    scanf("%d", &v[j]);
  }
  printf("Informe um numero: ");
  scanf("%d", &x);
  for (j = n - 1; j >= 0 && x < v[j]; j--)
  {
    v[j + 1] = v[j];
  }
  v[j + 1] = x;
  printf("\nVetor ordenado: [ ");
  for (int k = 0; k < n + 1; k++)
  {
    printf("%d ", v[k]);
  }
  printf("]");
  return 0;
}