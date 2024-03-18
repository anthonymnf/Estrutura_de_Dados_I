#include <stdio.h>

int positivos(int v[], int n)
{
  int x = v[n - 1];
  if (n == 1)
  {
    if (x > 0)
    {
      return 1;
    }
    return 0;
  }

  if (x > 0)
  {
    return 1 + positivos(v, n - 1);
  }
  return 0 + positivos(v, n - 1);
}

int main()
{
  int vet[5] = {-1, 0, 2, 3, -4};
  int count = positivos(vet, 5);
  printf("%d", count);
  return 0;
}
