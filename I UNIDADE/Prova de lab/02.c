#include <stdio.h>

void ordenarValores(int *x, int *y, int *z)
{
  if (*x > *y)
  {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  if (*y > *z)
  {
    int temp = *y;
    *y = *z;
    *z = temp;
  }

  // Aqui repetiu o msm if do primeiro, pois até esse momento
  //  x e y já podem terem trocado de valores
  if (*x > *y)
  {
    int temp = *x;
    *x = *y;
    *y = temp;
  }

  // Avisar se os valores forem iguais
  if (*x == *y || *y == *z)
  {
    printf("Ha valores iguais, por favor forneca outros valores\n");
  }
}

int main()
{
  int x, y, z;

  printf("Digite o valor de x: ");
  scanf("%i", &x);

  printf("Digite o valor de y: ");
  scanf("%i", &y);

  printf("Digite o valor de z: ");
  scanf("%i", &z);

  ordenarValores(&x, &y, &z);

  printf("Valores ordenados: x = %i, y = %i, z = %i\n", x, y, z);

  return 0;
}
