#include <stdio.h>

int soma(int n)
{
  if (n == 1)
  {

    return 1;
  }
  return n + soma(n - 1);
}

int main()
{
  int n;
  printf("Informe um numero: ");
  scanf("%d", &n);
  int sum = soma(n);
  printf("Soma: %d", sum);
  return 0;
}
