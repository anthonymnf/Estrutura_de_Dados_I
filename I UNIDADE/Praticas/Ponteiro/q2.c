// 2. Escreva um programa que contenha duas variáveis inteiras. Compare seus
// endereços e exiba o maior endereço.
#include <stdio.h>

int main()
{
  int n1 = 3, n2 = 7, *prt_n1, *prt_n2;
  prt_n1 = &n1;
  prt_n2 = &n2;
  if (prt_n1 > prt_n2)
  {
    printf("n1 tem o maior endereço. Endereço: %i", prt_n1);
  }
  else
  {
    printf("n2 tem o maior endereço. Endereço: %i", prt_n2);
  }
  return 0;
}
