#include <stdio.h>

void preencherArray(int *array, int valor)
{
  int *p = array;

  // Preenche o array com o valor dado até encontrar um marcador de fim(por exemplo aqui usei, -1)
  while (*p != -1)
  {
    *p = valor;
    p++;
  }
}

int main()
{
  // Como não foi especificado como deveria saber o tamanho do array
  // eu usei um marcador pra saber o fim do array e n precisar de ter esse conhecimento
  // apesar que como eu declarei o array já sabia o seu tamanho
  int meuArray[] = {0, 0, 0, 0, 0, -1}, *ptr;
  ptr = meuArray;
  preencherArray(meuArray, 50);

  printf("Array preenchido:\n");
  while (*ptr != -1)
  {
    printf("%i ", *ptr);
    ptr++;
  }
  printf("\n");

  return 0;
}
