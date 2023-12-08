// 1. Escreva um programa que declare um inteiro, um real e um char. Associe as
// variáveis aos ponteiros. Modifique os valores de cada variável usando os
// ponteiros. Imprima os valores das variáveis antes e após modificação.

#include <stdio.h>

int main()
{
  int n1, *ptr_n1;
  float n2, *ptr_n2;
  char letra, *ptr_char;
  n1 = 10;
  n2 = 5.5;
  letra = 'c';
  ptr_n1 = &n1;
  ptr_n2 = &n2;
  ptr_char = &letra;
  printf("Os valores eram:\t%i\t%f\t%c\n", n1, n2, letra);
  *ptr_n1 = 50;
  *ptr_n2 = 12.4;
  *ptr_char = 'a';
  printf("Os valores são:\t%i\t%f\t%c", n1, n2, letra);
  return 0;
}
