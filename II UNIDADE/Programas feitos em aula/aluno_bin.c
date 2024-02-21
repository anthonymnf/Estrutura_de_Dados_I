#include <stdio.h>

struct Aluno
{
  char nome[30];
  float media;
};

typedef struct Aluno Aluno;

void lerDados()
{
  Aluno a2;
  FILE *file = fopen("alunos.b", "rb");
  printf("\n");
  while (fread(&a2, sizeof(Aluno), 1, file))
  {
    printf("Aluno %s: %.2f\n", a2.nome, a2.media);
  }
  fclose(file);
}

void menu()
{
  printf("\nEscolha uma opcao:\n");
  printf("1-Cadastrar\n2-Listar alunos\n3-Sair\n");
  printf("-----------------------\n");
}

void cadastrar()
{
  FILE *file = fopen("alunos.b", "ab");
  Aluno aluno;
  printf("Informe o nome e a media do aluno:\n");
  scanf("%s %f", aluno.nome, &aluno.media);
  fwrite(&aluno, sizeof(Aluno), 1, file);
  fclose(file);
}

int main()
{
  int op;
  menu();

  scanf("%d", &op);
  while (op != 3)
  {
    if (op == 1)
    {
      cadastrar();
    }
    else if (op == 2)
    {
      lerDados();
    }
    menu();
    scanf("%d", &op);
  }

  return 0;
}
