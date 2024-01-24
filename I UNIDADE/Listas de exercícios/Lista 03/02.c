#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vet, n;
  printf("Informe o tamanho do vetor: ");
  scanf("%i", &n);
  vet = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
  {
    vet[i] = i;
  }
  printf("\nVet[0] = %i\n", vet[0]);
  printf("Vet[1] = %i\n", vet[1]);
  printf("Vet[%i] = %i\n", n - 2, vet[n - 2]);
  printf("Vet[%i] = %i", n - 1, vet[n - 1]);

  return 0;
}
