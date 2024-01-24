#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vet, tam, maiorElem = 0, cont = 0;
  printf("Informe o tamanho do array: ");
  scanf("%i", &tam);
  vet = (int *)malloc(tam * sizeof(int));
  printf("Preencha o vetor: \n");
  for (int i = 0; i < tam; i++)
  {
    printf("V[%i] = ", i);
    scanf("%i", &vet[i]);
    if (vet[i] > maiorElem)
    {
      maiorElem = vet[i];
    }
  }
  for (int i = 0; i < tam; i++)
  {
    if (vet[i] == maiorElem)
    {
      cont++;
    }
  }

  printf("\nO maior elemento e %i e aparecceu %i vezes", maiorElem, cont);

  return 0;
}
