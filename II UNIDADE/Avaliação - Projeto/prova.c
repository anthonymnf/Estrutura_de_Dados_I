#include <stdio.h>

// Projeto de um sistema de fármacia (EM CONSTRUÇÃO)

// Funções pra se adicionar:
// (X) Login;
// (X) Modo cliente e admin;
//  (X) No modo admin terá: cadastrar, listar, editar e excluir
//  (X) No modo cliente terá: Simulação de comprar, listar produtos, Ordenar produtos por preço. Na simulação de compra diminuir a quantidade de estoque, buscar por um remédio em específico;
// - Verificação de validade de e-mail: o programa deve permitir que se verifique a validade do e-mail de um usuário. Para ser válido, o e-mail precisa conter o caractere @ e a quantidade de caracteres dele precisa se menor que 80. Além disso, para ser válido, NÃO pode haver outro e-mail cadastrado no sistema com o mesmo valor. Isso pode ser feito antes do login
// (x) Mensagem de boas vindas: o programa deve apresentar uma mensagem de boas-vindas para o usuário. A mensagem de boas-vindas deve estar relacionado ao tema da aplicação/projeto escolhido pelo aluno.

struct Remedio
{
  int codigo;
  char nome[30];
  float preco;
  int estoque;
};

typedef struct Remedio Remedio;

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

// Função responsável por excluir um remédio em pharma.b, através do seu código
void excluir(int cod)
{
  int n = tamanho();
  Remedio v[n];
  FILE *file = fopen("pharma.b", "rb");
  int i = 0;
  while (fread(&v[i], sizeof(Remedio), 1, file))
  {
    i++;
  }
  fclose(file);
  file = fopen("pharma.b", "wb");
  for (i = 0; i < n; i++)
  {
    if (v[i].codigo != cod)
    {
      fwrite(&v[i], sizeof(Remedio), 1, file);
    }
  }
  fclose(file);
}

// Função responsável por editar um remédio em pharma.b, através do seu código
void editar(int cod)
{
  int n = tamanho();
  Remedio v[n];
  FILE *file = fopen("pharma.b", "rb");
  int i = 0;
  while (fread(&v[i], sizeof(Remedio), 1, file))
  {
    i++;
  }
  fclose(file);
  file = fopen("pharma.b", "wb");
  for (i = 0; i < n; i++)
  {
    if (v[i].codigo == cod)
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
        v[i].preco = price;
        printf("Preco atualizado: %.2f\n", v[i].preco);
      }
      else
      {
        int stock;
        printf("Informe o novo estoque:\n");
        scanf("%i", &stock);
        v[i].estoque = stock;
        printf("Estoque atualizado: %d\n", v[i].estoque);
      }
    }

    fwrite(&v[i], sizeof(Remedio), 1, file);
  }
  fclose(file);
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
  printf("- Email valido\n");
  printf("- Para entrar no Adm Mode e Id = 1 e Senha = 11\n");
  printf("- Para entrar no Client Mode e Id = 2 e Senha = 22\n");
  printf("---------------------\n");
  Login user;
  int verificado = 0;
  // Chamar aqui a validação de email, essa função vai retornar um número q vou tratado com o if else
  printf("Insira um email valido e ainda nao cadastrado no sistema\n");
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
    menuAdmin();
    scanf("%d", &op);
  }
}

float carrinhoDeCompras(int cod, int quant)
{
  // Retirando remedios do estoque
  int n = tamanho();
  Remedio v[n];
  FILE *file = fopen("pharma.b", "rb");
  int i = 0;
  while (fread(&v[i], sizeof(Remedio), 1, file))
  {
    i++;
  }
  fclose(file);
  file = fopen("pharma.b", "wb");
  for (i = 0; i < n; i++)
  {
    if (v[i].codigo == cod)
    {
      v[i].estoque = v[i].estoque - quant;
    }

    fwrite(&v[i], sizeof(Remedio), 1, file);
  }
  fclose(file);
  // Parte responsável por retornar o preço dos remedios que serão comprados
  file = fopen("pharma.b", "rb");
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
    menuClient();
    scanf("%d", &op);
  }
}

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