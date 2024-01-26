#include <stdio.h>
#include <stdlib.h>
int compararInteiros(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

int main()
{
  int array[] = {4, 2, 8, 1, 6, 3};
  int tamanho = sizeof(array) / sizeof(array[0]);
  qsort(array, tamanho, sizeof(int), compararInteiros);
  // Agora, 'array' está ordenado.
  // ...
  for (int i = 0; i < 6; i++)
  {
    /* code */
    printf("%i ", array[i]);
  }
  return 0;
}
