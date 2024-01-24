#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *vet, tam, par = 0, impar = 0;
  printf("Informe o tamanho do vetor: ");
  scanf("%i", &tam);
  vet = (int *)malloc(tam * sizeof(int));
  // Lendo valores e verificando os impares e pares
  printf("Informe os valores do vetor:\n");
  for (int i = 0; i < tam; i++)
  {
    scanf("%i", &vet[i]);
    if (vet[i] % 2 == 0)
    {
      par++;
    }
    else
    {
      impar++;
    }
  }

  // Printando valores
  for (int i = 0; i < tam; i++)
  {
    printf("V[%i] = %i\n", i, vet[i]);
  }
  printf("Quantidade de pares: %i", par);
  printf("\nQuantidade de impares: %i", impar);
  free(vet);

  return 0;
}
