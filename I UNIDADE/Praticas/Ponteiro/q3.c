// 3. Escreva um programa que contenha duas variáveis inteiras. Leia essas variáveis
// do teclado. Em seguida, compare seus endereços e exiba o conteúdo do maior
// endereço.

#include <stdio.h>

int main()
{
  int n1, n2, *prt_n1, *prt_n2;
  prt_n1 = &n1;
  prt_n2 = &n2;
  printf("Insira o valor de n1:");
  scanf("%i", &n1);
  printf("Insira o valor de n2:");
  scanf("%i", &n2);

  if (prt_n1 > prt_n2)
  {
    printf("n1 tem o maior endereço. E seu valor e: %i\n", *prt_n1);
    printf("%i\n", prt_n1);
    printf("%i", prt_n2);
  }
  else
  {
    printf("n2 tem o maior endereço. E seu valor e: %i", *prt_n2);
  }
  return 0;
}
