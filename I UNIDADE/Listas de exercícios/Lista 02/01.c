#include <stdio.h>

void swap(int *a, int *b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}

int main()
{
  int num1, num2;
  printf("Informe dois numeros inteiros.");
  printf("\nNumero 1: ");
  scanf("%i", &num1);
  printf("Numero 2: ");
  scanf("%i", &num2);
  swap(&num1, &num2);
  printf("Trocando valores....");
  printf("\nNumero 1: %i", num1);
  printf("\nNumero 2: %i", num2);
  return 0;
}
