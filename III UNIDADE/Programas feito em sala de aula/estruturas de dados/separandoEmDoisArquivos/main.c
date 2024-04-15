#include <stdio.h>
#include "estudante.h"

int main()
{
  int n;
  printf("Informe a quantidade de estudantes: ");
  scanf("%d", &n);
  Estudante *v = criaLista(n);
  lerEstudantes(n, v);
  imprimeEstudantes(n, v);
  return 0;
}
