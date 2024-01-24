#include <stdio.h>
#include <stdlib.h>

void uniao(int *v1, int n1, int *v2, int n2)
{
  int *v3, tam3 = n1 + n2;
  v3 = (int *)malloc(tam3 * sizeof(int));
  for (int i = 0; i < n1; i++)
  {
    v3[i] = v1[i];
  }
  for (int i = 0; i < n2; i++)
  {
    v3[i + n1] = v2[i];
  }
  for (int i = 0; i < tam3; i++)
  {
    printf("V3[%i] = %i\n", i, v3[i]);
  }

  free(v3);
}

int main()
{
  int *v1, n1, *v2, n2;
  printf("Informe o tamanho do vetor V1: ");
  scanf("%i", &n1);
  v1 = (int *)malloc(n1 * sizeof(int));
  printf("Informe o tamanho do vetor V2: ");
  scanf("%i", &n2);
  v2 = (int *)malloc(n2 * sizeof(int));
  printf("Informe os valores do vetor 1: \n");
  for (int i = 0; i < n1; i++)
  {
    printf("V1[%i] = ", i);
    scanf("%i", &v1[i]);
  }
  printf("Informe os valores do vetor 2: \n");
  for (int i = 0; i < n2; i++)
  {
    printf("V2[%i] = ", i);
    scanf("%i", &v2[i]);
  }
  printf("\n-------------------\n");
  uniao(v1, n1, v2, n2);
  free(v1);
  free(v2);
  return 0;
}
