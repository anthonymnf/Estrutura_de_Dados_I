#include <stdio.h>
#include <stdlib.h>

/* Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova,
nota da segunda prova e nota da terceira prova.
a) Permita ao usuário entrar com os dados de 5 alunos.
b) Encontre o aluno com maior nota da primeira prova.
c) Encontre o aluno com maior média geral.
d) Encontre o aluno com menor média geral
e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprovação. */

struct pessoa
{

  int matricula;
  char nome[20];
  float n1, n2, n3;
};

int main()
{

  struct pessoa aluno[3];
  float contadorPrimeira = 0, contadorMaior = 0, contadorMenor = 10, media;
  int i, nomePrimeira = 0, nomeMaior = 0, nomeMenor = 0;

  for (i = 0; i < 3; i++)
  {

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

    if (contadorPrimeira < aluno[i].n1)
    {
      contadorPrimeira = aluno[i].n1;
      nomePrimeira = i;
    }

    if (contadorMaior < media)
    {
      contadorMaior = media;
      nomeMaior = i;
    }

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
