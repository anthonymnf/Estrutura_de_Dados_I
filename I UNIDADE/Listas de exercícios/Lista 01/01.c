#include <stdio.h>

struct dadosPessoais
{
  char nome[30];
  int idade;
  char endereco[50];
};

int main()
{
  typedef struct dadosPessoais dados;
  dados pessoa;
  printf("Informe seus dados pessoais:\n");
  printf("Nome: ");
  scanf("%29[^\n]", pessoa.nome);
  printf("Idade: ");
  scanf("%i", &pessoa.idade);
  fflush(stdin);
  printf("Endereço: ");
  scanf("%49[^\n]", pessoa.endereco);
  fflush(stdin);
  printf("-----------------------");
  printf("\nDados informados:");
  printf("%s, ", pessoa.nome);
  printf("%i anos.\n", pessoa.idade);
  printf("Rua: %s", pessoa.endereco);

  return 0;
}
