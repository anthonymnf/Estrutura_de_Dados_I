#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Projeto de um sistema de fármacia (FINALIZADO)

struct Remedio
{
  int codigo;
  char nome[30];
  float preco;
  int estoque;
};

typedef struct Remedio Remedio;

// Funções adicionadas para lidar com listas
struct no
{
  Remedio dado;
  struct no *prox;
};

typedef struct no No;

typedef struct
{
  No *inicio;
} Lista;

void adicionaFim(Lista *lista, Remedio e)
{
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = e;
  novo->prox = NULL;
  if (lista->inicio == NULL)
  {
    lista->inicio = novo;
  }
  else
  {
    No *pi;
    for (pi = lista->inicio; pi->prox != NULL; pi = pi->prox)
      ;
    pi->prox = novo;
  }
}

void editarLista(Lista *lista, int cod)
{
  if (lista->inicio == NULL)
  {
    printf("Lista vazia\n");
  }
  else
  {
    No *pi;
    for (pi = lista->inicio; pi != NULL && pi->dado.codigo != cod; pi = pi->prox)
      ;
    if (pi == NULL)
    {
      printf("Remedio nao encontrado\n");
    }
    else
    {
      int option;
      printf("Escolha uma opcao:\n");
      printf("1 - Editar preco\n");
      printf("Qualquer outro numero - Editar estoque\n");
      scanf("%d", &option);
      if (option == 1)
      {
        float price;
        printf("Informe o novo preco:\n");
        scanf("%f", &price);
        pi->dado.preco = price;
        printf("Preco atualizado: %.2f\n", pi->dado.preco);
      }
      else
      {
        int stock;
        printf("Informe o novo estoque:\n");
        scanf("%i", &stock);
        pi->dado.estoque = stock;
        printf("Estoque atualizado: %d\n", pi->dado.estoque);
      }
    }
  }
}

void deletar(Lista *lista, int cod)
{
  if (lista->inicio == NULL)
  {
    printf("Lista vazia\n");
  }
  else
  {
    No *pa = NULL;
    No *pi;
    for (pi = lista->inicio; pi->prox != NULL && pi->dado.codigo != cod; pi = pi->prox)
    {
      pa = pi;
    }
    if (pa == NULL)
    {
      if (pi->dado.codigo == cod)
      {
        lista->inicio = pi->prox;
        free(pi);
      }
      else
      {
        printf("Elemento nao encontrado\n");
      }
    }
    else
    {
      if (pi->dado.codigo == cod)
      {
        pa->prox = pi->prox;
        free(pi);
      }
      else
      {
        printf("Elemento nao encontrado\n");
      }
    }
  }
}

void lerLista(Lista *lista)
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio e;
  while (fread(&e, sizeof(Remedio), 1, file))
  {
    adicionaFim(lista, e);
  }
  fclose(file);
}

void salvaLista(Lista *lista)
{
  FILE *file = fopen("pharma.b", "wb");
  No *pi;
  for (pi = lista->inicio; pi != NULL; pi = pi->prox)
  {
    fwrite(&pi->dado, sizeof(Remedio), 1, file);
  }
  fclose(file);
}

void mostrar(Lista *lista)
{
  No *pi;
  for (pi = lista->inicio; pi != NULL; pi = pi->prox)
  {
    Remedio dado = pi->dado;
    printf("%d %s\n", dado.codigo, dado.nome);
  }
}

void ordenarLista()
{
  Lista lista;
  lista.inicio = NULL;
  lerLista(&lista);
  No *pi;
  No *pj;
  No *pfim = NULL;
  if (lista.inicio == NULL)
  {
    return;
  }
  for (pi = lista.inicio; pi->prox != NULL; pi = pi->prox)
  {
    for (pj = lista.inicio; pj->prox != pfim; pj = pj->prox)
    {
      if (pj->dado.codigo > pj->prox->dado.codigo)
      {
        Remedio temp = pj->dado;
        pj->dado = pj->prox->dado;
        pj->prox->dado = temp;
      }
    }
  }
  mostrar(&lista);
  salvaLista(&lista);
}

// Esse será o menu e opções do modo admin
void menuAdmin()
{
  printf("\nBem vindo ao modo admin!\n");
  printf("\nEscolha uma opcao:\n");
  printf("1 - Cadastar remedio\n");
  printf("2 - Listar remedios\n");
  printf("3 - Buscar remedio\n");
  printf("4 - Quantidade de remedios\n");
  printf("5 - Excluir um remedio\n");
  printf("6 - Editar um remedio\n");
  printf("7 - Remedios com o estoque acabando\n");
  printf("8 - Cadastrar promocao\n");
  printf("9 - Ordenar Remedios por seu codigo\n");
  printf("0 - Sair\n");
  printf("===================\n");
}

// Esse será o menu e opções do modo client
void menuClient()
{
  printf("\nSeja bem-vindo a nossa farmacia!\n");
  printf("\nEscolha uma opcao:\n");
  printf("1 - Comprar remedios\n");
  printf("2 - Listar remedios\n");
  printf("3 - Buscar remedio\n");
  printf("4 - Quantidade de remedios\n");
  printf("5 - Remedios que cabem no seu bolso!\n");
  printf("6 - Buscar remedios em promocao\n");
  printf("0 - Sair\n");
  printf("===================\n");
}

// Função responsável por cadastrar remédios em pharma.b
void cadastrar()
{
  FILE *file = fopen("pharma.b", "ab");
  Remedio a;
  printf("Informe os dados do remedio na ordem: Codigo Nome Preco e Estoque\n");
  scanf("%d %s %f %d", &a.codigo, a.nome, &a.preco, &a.estoque);
  fwrite(&a, sizeof(Remedio), 1, file);
  fclose(file);
}

// Função responsável por cadastrar remédios em promoçaõ no arquivo promocao.b
void cadastrarPromocao()
{
  FILE *file = fopen("promocao.b", "ab");
  int a;
  printf("Informe o codigo do remedio em promocao:\n");
  scanf("%d", &a);
  fwrite(&a, sizeof(int), 1, file);
  fclose(file);
}

// Função responsável por buscar remédios em pharma.b
void buscar(int cod)
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int entrou = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    if (a.codigo == cod)
    {
      printf("\nNome: %s\n", a.nome);
      printf("- Codigo: %d\n", a.codigo);
      printf("- Preco: %.2f\n", a.preco);
      printf("- Quantidade em estoque: %d\n", a.estoque);
      entrou = 1;
    }
  }
  if (entrou == 0)
  {
    printf("Remedio nao encontrado\n");
  }
  fclose(file);
}

// Função responsável por buscar remédios em promoção no arquivo promocao.b
void buscarPromocao()
{
  FILE *file = fopen("promocao.b", "rb");
  int a;
  printf("Remedios em promocao:\n");
  while (fread(&a, sizeof(int), 1, file))
  {
    buscar(a);
  }
  fclose(file);
}

// Função responsável por listar os remédios de pharma.b
void listar()
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    printf("\nNome: %s\n", a.nome);
    printf("- Codigo: %d\n", a.codigo);
    printf("- Preco: %.2f\n", a.preco);
    printf("- Quantidade em estoque: %d\n", a.estoque);
  }
  fclose(file);
}

// Função responsável por contar a quantidade de remédios cadastrados em pharma.b
int tamanho()
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int cont = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    cont++;
  }
  fclose(file);
  return cont;
}

// Função que checa os remédios com o estoque acabando, aqui o parametro para saber que está acabando é ter menos de 50 no estoque
void estoqueAcabando()
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int entrou = 0;
  printf("Remedios com o estoque acabando: \n");
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    if (a.estoque < 50)
    {
      printf("\nNome: %s\n", a.nome);
      printf("- Codigo: %d\n", a.codigo);
      printf("- Quantidade em estoque: %d\n", a.estoque);
      entrou++;
    }
  }
  if (entrou == 0)
  {
    printf("Estoque cheio, nenhum remedio com menos de 50 unidades no estoque.\n");
  }

  fclose(file);
}

// Função responsável por excluir um remédio em pharma.b, através do seu código
void excluir(int cod)
{
  Lista lista;
  lista.inicio = NULL;
  lerLista(&lista);
  deletar(&lista, cod);
  salvaLista(&lista);
}

// Função responsável por editar um remédio em pharma.b, através do seu código
void editar(int cod)
{
  Lista lista;
  lista.inicio = NULL;
  lerLista(&lista);
  editarLista(&lista, cod);
  salvaLista(&lista);
}

// Partes responsáveis pela verificação do email
#define MAX_EMAIL_LENGTH 80

// Função para verificar se o email já existe no arquivo
int verificarEmailExistente(const char *email)
{
  FILE *arquivo = fopen("emails.txt", "r");
  if (arquivo == NULL)
  {
    return 0; // Arquivo não existe, então email não está cadastrado
  }
  char linha[MAX_EMAIL_LENGTH];
  while (fgets(linha, MAX_EMAIL_LENGTH, arquivo) != NULL)
  {
    // Remover o caractere de nova linha de fgets
    linha[strcspn(linha, "\n")] = 0;
    if (strcmp(linha, email) == 0)
    {
      fclose(arquivo);
      return 1; // Email já cadastrado
    }
  }
  fclose(arquivo);
  return 0; // Email não encontrado no arquivo
}

// Função para verificar a validade do email
int verificarEmail(const char *email)
{
  if (strlen(email) >= MAX_EMAIL_LENGTH)
  {
    return 0; // Email muito longo
  }
  char *posArroba = strchr(email, '@');
  if (posArroba == NULL)
  {
    return 0; // Email não contém @
  }
  if (verificarEmailExistente(email))
  {
    return 0; // Email já cadastrado
  }
  return 1; // Email válido
}

int email()
{
  char email[MAX_EMAIL_LENGTH];
  int valido = 0;

  while (!valido)
  {
    printf("Digite seu email: ");
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    // Remover o caractere de nova linha de fgets
    email[strcspn(email, "\n")] = 0;

    if (verificarEmail(email))
    {
      valido = 1;
    }
    else
    {
      printf("Email invalido ou ja cadastrado. Por favor, tente novamente.\n");
    }
  }

  // Agora que temos um email válido, vamos adicioná-lo ao arquivo
  FILE *arquivo = fopen("emails.txt", "a");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo para escrita.\n");
    return 1;
  }
  fprintf(arquivo, "%s\n", email);
  fclose(arquivo);

  printf("Email cadastrado com sucesso!\n");

  return 0;
}

// Partes responsáveis pelo login nos dois modos
struct Login
{
  char email[81];
  int id;
  int senha;
};

typedef struct Login Login;

int login()
{
  printf("\n---------------------\n");
  printf("INFORMES PARA REUDISMAM\n");
  printf("As funcoes estao divididas em dois modos: Admin Mode e Client Mode, cada uma com suas funcoes especificas\n");
  printf("Credenciais para entrar nos modos:\n");
  printf("- Email valido e ainda nao cadastrado\n");
  printf("- Para entrar no Adm Mode e Id = 1 e Senha = 11\n");
  printf("- Para entrar no Client Mode e Id = 2 e Senha = 22\n");
  printf("---------------------\n");
  Login user;
  int verificado = email();

  while (verificado == 0)
  {
    printf("Informe o id: ");
    scanf("%d", &user.id);
    printf("Informe a senha: ");
    scanf("%d", &user.senha);

    if (user.id == 1 && user.senha == 11)
    {
      verificado = 1;
      return 1; // Igual a entrar no modo admin
    }
    else if (user.id == 2 && user.senha == 22)
    {
      verificado = 1;
      return 2; // Igual a entrar no modo cliente/user
    }
    else
    {
      printf("Id ou senha incorretos, tente novamente!\n");
    }
  }

  return 0;
}
// Função responsável por tratar o modo adm
void admMode()
{
  int op;
  menuAdmin();
  scanf("%d", &op);
  while (op != 0)
  {
    if (op == 1)
    {
      cadastrar();
    }
    else if (op == 2)
    {
      listar();
    }
    else if (op == 3)
    {
      int cod;
      printf("Informe o codigo do produto:\n");
      scanf("%d", &cod);
      buscar(cod);
    }
    else if (op == 4)
    {
      int n = tamanho();
      printf("Quantidade de remedios na farmacia: %d\n", n);
    }
    else if (op == 5)
    {
      int cod;
      printf("Informe o codigo do remedio que voce deseja excluir:\n");
      scanf("%d", &cod);
      excluir(cod);
    }
    else if (op == 6)
    {
      int cod;
      printf("Informe o codigo do remedio que voce deseja editar:\n");
      scanf("%d", &cod);
      editar(cod);
    }
    else if (op == 7)
    {
      estoqueAcabando();
    }
    else if (op == 8)
    {
      cadastrarPromocao();
    }
    else if (op == 9)
    {
      ordenarLista();
    }
    menuAdmin();
    scanf("%d", &op);
  }
}

void retirarDoEstoqueComLista(Lista *lista, int cod, int quant)
{
  No *pi;
  for (pi = lista->inicio; pi != NULL && pi->dado.codigo != cod; pi = pi->prox)
    ;
  if (pi == NULL)
  {
    printf("Remedio nao encontrado\n");
  }
  else
  {
    pi->dado.estoque = pi->dado.estoque - quant;
  }
}

// Função que faz o carrinho de compras e simula uma compra de remedios, é fornecido pelo cliente o código e a quantidade do remédio
float carrinhoDeCompras(int cod, int quant)
{
  // Retirando remedios do estoque
  Lista lista;
  lista.inicio = NULL;
  lerLista(&lista);
  retirarDoEstoqueComLista(&lista, cod, quant);
  salvaLista(&lista);
  // Parte responsável por retornar o preço dos remedios que serão comprados
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int entrou = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    if (a.codigo == cod)
    {
      printf("\nNome: %s\n", a.nome);
      printf("- Codigo: %d\n", a.codigo);
      printf("- Preco: %.2f\n", a.preco);
      printf("- Quantidade em estoque: %d\n", a.estoque + quant); // Somei de volta a quantidade do estoque pois antes de finalizar a comprar eu já retirei do pharma.b
      entrou = 1;
      return a.preco * quant;
    }
  }
  if (entrou == 0)
  {
    printf("Codigo de remedio incorreto\n");
  }
  fclose(file);

  return 0;
}

// Função que busca os remédios que estão abaixo de um valor X de dinheiro fornecido pelo cliente
void remediosBaratos(float x)
{
  FILE *file = fopen("pharma.b", "rb");
  Remedio a;
  int entrou = 0;
  while (fread(&a, sizeof(Remedio), 1, file))
  {
    if (a.preco <= x)
    {
      printf("\nNome: %s\n", a.nome);
      printf("- Codigo: %d\n", a.codigo);
      printf("- Preco: %.2f\n", a.preco);
      printf("- Quantidade em estoque: %d\n", a.estoque);
      entrou = 1;
    }
  }
  if (entrou == 0)
  {
    printf("Nao ha remedio com um preco menor ou igual ao do que o informado\n");
  }
  fclose(file);
}
// Função responsável por tratar o modo cliente
void clientMode()
{
  int op;
  menuClient();
  scanf("%d", &op);
  while (op != 0)
  {
    if (op == 1)
    {
      int qnt;
      printf("Quantos itens voce deseja comprar?\n");
      scanf("%d", &qnt);
      float cart = 0;
      for (int i = 0; i < qnt; i++)
      {
        int cod, qnt;
        printf("Informe o codigo do remedio: ");
        scanf("%d", &cod);
        printf("Informe a quantidade: ");
        scanf("%d", &qnt);
        cart += carrinhoDeCompras(cod, qnt);
      }
      printf("Total da compra foi: %.2f\n", cart);
    }
    else if (op == 2)
    {
      listar();
    }
    else if (op == 3)
    {
      int cod;
      printf("Informe o codigo do produto:\n");
      scanf("%d", &cod);
      buscar(cod);
    }
    else if (op == 4)
    {
      int n = tamanho();
      printf("Quantidade de remedios na farmacia: %d\n", n);
    }
    else if (op == 5)
    {
      float x;
      printf("Informe o quanto voce esta disposto a pagar e descubra os remedios que cabem no seu bolso: ");
      scanf("%f", &x);
      remediosBaratos(x);
    }
    else if (op == 6)
    {
      buscarPromocao();
    }

    menuClient();
    scanf("%d", &op);
  }
}

// Função que exibi a mensagem de boas vindas do programa
void mensagemDeBoasVindas()
{
  printf("Bem-vindo a VitalFarMed, onde saude e bem-estar se encontram em cada visita! Aqui, nossa missao e cuidar de voce e de sua familia com dedicacao e expertise. Entre em nossa loja virtual e descubra uma ampla variedade de produtos farmaceuticos de qualidade, aliados a um atendimento personalizado que faz toda a diferenca. Na VitalFarMed, sua saude e nossa prioridade numero um. Juntos, vamos trilhar o caminho para uma vida mais saudavel e feliz. Seja bem-vindo a sua nova casa de saude e bem-estar!\n");
  printf("\nVitalFarMed: Vitalizando sua vida, medicando seu bem-estar!\n");
}

int main()
{
  mensagemDeBoasVindas();
  int checkout = login();
  if (checkout == 1)
  {
    admMode();
  }
  else
  {
    clientMode();
  }

  return 0;
}