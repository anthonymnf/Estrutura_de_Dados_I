#include <stdio.h>
#include <stdlib.h>

struct pessoa
{

  int matricula;
  char nome[20];
  float n1, n2, n3;
};

int main()
{
  typedef struct pessoa alun;
  alun aluno[5];
  float contadorPrimeira = 0, contadorMaior = 0, contadorMenor = 10, media;
  int i, nomePrimeira = 0, nomeMaior = 0, nomeMenor = 0;

  for (i = 0; i < 5; i++)
  {
    // Pegando os dados dos 5 alunos
    printf("Informe a matricula do aluno %d: ", (i + 1));
    scanf("%d", &aluno[i].matricula);
    printf("Informe o nome do aluno: ");
    scanf("%s", &aluno[i].nome);
    printf("Nota 1: ");
    scanf("%f", &aluno[i].n1);
    printf("Nota 2: ");
    scanf("%f", &aluno[i].n2);
    printf("Nota 3: ");
    scanf("%f", &aluno[i].n3);

    system("cls");

    media = (aluno[i].n1 + aluno[i].n2 + aluno[i].n3) / 3;

    // Conferindo se o aluno i possui a maior 1° nota
    if (contadorPrimeira < aluno[i].n1)
    {
      contadorPrimeira = aluno[i].n1;
      nomePrimeira = i;
    }

    // Conferindo se o aluno i possui a maior media
    if (contadorMaior < media)
    {
      contadorMaior = media;
      nomeMaior = i;
    }

    // Conferindo se o aluno i possui a menor media
    if (contadorMenor > media)
    {
      contadorMenor = media;
      nomeMenor = i;
    }

    system("cls");
  }

  // Geral
  printf("Situacao geral:\n");
  for (i = 0; i < 5; i++)
  {
    media = (aluno[i].n1 + aluno[i].n2 + aluno[i].n3) / 3;
    if (media >= 6)
      printf("%s aprovado!! =D\n", aluno[i].nome);
    else
      printf("%s reprovado!! =(\n", aluno[i].nome);
  }
  printf("%s teve a maior nota 1 com %.1f\n", aluno[nomePrimeira].nome, contadorPrimeira);
  printf("%s teve a maior media com %.1f\n", aluno[nomeMaior].nome, contadorMaior);
  printf("%s teve a menor media com %.1f\n", aluno[nomeMenor].nome, contadorMenor);

  return 0;
}
