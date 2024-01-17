#include <stdio.h>

int sum(int *num1, int *num2)
{
  *num1 = *num1 * 2;
  *num2 = *num2 * 2;
  int sum;
  return sum = *num1 + *num2;
}

int main()
{
  int a, b;
  printf("Informe dois valores inteiros: \n");
  printf("-A: ");
  scanf("%i", &a);
  printf("-B: ");
  scanf("%i", &b);
  int doubleSum = sum(&a, &b);
  printf("-Dobro de A: %i", a);
  printf("\n-Dobro de B: %i", b);
  printf("\n-Soma do dobro de A e B: %i", doubleSum);
  return 0;
}
