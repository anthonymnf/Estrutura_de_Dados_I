// Aqui tem apenas uma função que realiza uma busca binária recursiva
// Será feita uma busca por a matrícula de um estudante em um vetor de estudantes
// A ideia de busca binária está presente então é possivel adaptar essa busca de qualquer forma
// Ela funciona como a busca de um dicionário, repartindo no meio e buscando com base nisso

struct estudante
{
  int mat;
  char nome[30];
  float n1, n2, n3;
};

struct estudante v[4];

int buscaBinariaRecursiva(int matricula, struct estudante v[], int inicio, int final)
{
  if (inicio > final)
  {
    return -1;
  }
  int meio = (inicio + final) / 2;
  if (v[meio].mat == matricula)
  {
    return meio;
  }
  if (v[meio].mat < matricula)
  {
    return buscaBinariaRecursiva(matricula, v, meio + 1, final);
  }
  return buscaBinariaRecursiva(matricula, v, inicio, meio - 1); // Haverá esse return caso v[meio].mat > matricula
}