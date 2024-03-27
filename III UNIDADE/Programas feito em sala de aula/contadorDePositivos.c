#include <stdio.h>
#include <stdlib.h>

// Foi pedido pra fzr um programa que contar numeros positivos sem usar estruturas de repetição. As estruturas só eram permitidas pra ler o vetor
int contarInteiro(int v[], int ind, int f)
{
  if (ind < f)
  {
    if (v[ind] > 0)
    {
      return 1 + contarInteiro(v, ind + 1, f);
    }
    return contarInteiro(v, ind + 1, f);
  }
  return 0;
}

int main()
{
  int n;
  printf("Tamanho do vetor: ");
  scanf("%d", &n);
  int *vet1;
  vet1 = (int *)malloc(n * sizeof(int));
  printf("Informe os valores do vetor:\n");
  for (int p = 0; p < n; p++)
  {
    scanf("%d", &vet1[p]);
  }
  int count = contarInteiro(vet1, 0, n);
  printf("Quantidade de numeros positivos: %d", count);
  return 0;
}
