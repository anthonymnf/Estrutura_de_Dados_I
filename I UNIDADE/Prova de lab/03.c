#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Letra A
struct vendedor
{
  char nome[50];
  int cpf;
  float salario;
};

// Enunciado
struct carro
{
  char marca[20];
  char modelo[20];
  int ano;
  // Usei char pois tem tanto letras quanto numeros na placa
  char placa[7];
  float valor;
  struct vendedor vendedor;
};

typedef struct carro carro;

int main()
{
  carro *carros;
  int quant, idMaisCaro = 0; // Inicializei, pra não ter erro caso só tenha um carro cadastrado
  float carroMaisCaro = 0;
  printf("Informe a quantidade de carros a serem cadastrados: ");
  scanf("%i", &quant);
  carros = (carro *)malloc(quant * sizeof(carro));

  fflush(stdin);
  printf("Informe: \n");
  for (int i = 0; i < quant; i++)
  {
    printf("Carro %i\n", i);
    printf("-Marca: ");
    gets(carros[i].marca);
    fflush(stdin); // Uso fflush pois as vezes meu compilador buga e o fflush me ajuda a evitar esse bugs nas leituras de string
    printf("-Modelo: ");
    gets(carros[i].modelo);
    fflush(stdin);
    printf("-Ano: ");
    scanf("%i", &carros[i].ano);
    fflush(stdin);
    printf("-Placa: ");
    gets(carros[i].placa);
    fflush(stdin);
    printf("-Valor: ");
    scanf("%f", &carros[i].valor);
    fflush(stdin);
    printf("Area do vendedor: \n");
    printf("-Nome do vendedor: ");
    gets(carros[i].vendedor.nome);
    fflush(stdin);
    printf("-CPF: ");
    scanf("%i", &carros[i].vendedor.cpf);
    fflush(stdin);
    printf("-Salario: ");
    scanf("%f", &carros[i].vendedor.salario);
    fflush(stdin);
    printf("---------------------\n");
  }

  // Letra B
  for (int i = 0; i < quant; i++)
  {
    if (carros[i].valor > carroMaisCaro)
    {
      carroMaisCaro = carros[i].valor;
      idMaisCaro = i;
    }
  }

  printf("A seguir estao as informacoes do carro mais caro da loja:\n");
  printf("-Marca: %s\n", carros[idMaisCaro].marca);
  printf("-Modelo: %s\n", carros[idMaisCaro].modelo);
  printf("-Ano: %i\n", carros[idMaisCaro].ano);
  printf("-Placa: %s\n", carros[idMaisCaro].placa);
  printf("-Valor: %.2f\n", carros[idMaisCaro].valor);
  printf("-----------------------\n");

  // Letra C
  printf("Modelos de carros com o ano inferior a 2010:\n");
  for (int i = 0; i < quant; i++)
  {
    if (carros[i].ano < 2010)
    {
      printf("- %s\n", carros[i].modelo);
    }
  }

  free(carros);
  return 0;
}
