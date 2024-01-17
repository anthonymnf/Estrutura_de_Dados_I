#include <stdio.h>

void encontrarMinEMax(const int vetor[], int tamanho, int *min, int *max)
{
  // Verificação de parâmetros
  if (vetor == NULL || min == NULL || max == NULL || tamanho <= 0)
  {
    printf("Parâmetros inválidos.\n");
    return;
  }

  // Inicialização dos valores mínimo e máximo com o primeiro elemento do vetor
  *min = *max = vetor[0];

  for (int i = 1; i < tamanho; i++)
  {
    if (vetor[i] < *min)
    {
      *min = vetor[i];
    }
    else if (vetor[i] > *max)
    {
      *max = vetor[i];
    }
  }
}

int main()
{
  // Como n foi especificado que deveria pedir pro usuário
  // os valores do vetor, então inicializei um vetor qualquer
  int numeros[] = {5, 3, 8, 2, 7, 1, 9, 4, 6};
  int tamanho = sizeof(numeros) / sizeof(numeros[0]);
  int valorMin, valorMax;

  encontrarMinEMax(numeros, tamanho, &valorMin, &valorMax);

  printf("Mínimo: %d\n", valorMin);
  printf("Máximo: %d\n", valorMax);

  return 0;
}
