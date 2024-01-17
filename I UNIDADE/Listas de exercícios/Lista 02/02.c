#include <stdio.h>

int main()
{
  // Como n foi especificado que deveria pedir pro usuário
  // os valores do vetor, então inicializei um vetor qualquer
  int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *ptr = &vet[0];
  printf("Endereços:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("V[%i]= %d\n", i, ptr);
    ptr++;
  }

  return 0;
}
