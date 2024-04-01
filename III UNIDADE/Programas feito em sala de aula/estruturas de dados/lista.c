typedef struct
{
  int mat;
  char nome[50];
  float media;
} Estudante;

struct no
{
  Estudante dado;
  struct no *prox;
};

typedef struct no No;
