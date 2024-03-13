#include <stdio.h>

// A função login terá um retorno inteiro que será tratado na main pra decidir qual menu e quais opções serão apresentadas ao usuário

struct Login
{
  int user;
  int senha;
};

typedef struct Login Login;

int login()
{
  Login user;
  int verificado = 0;
  while (verificado == 0)
  {
    printf("Informe o login: ");
    scanf("%d", &user.user);
    printf("Informe a senha: ");
    scanf("%d", &user.senha);

    if (user.user == 1 && user.senha == 11)
    {
      printf("Bem vindo ao modo admin!\n");
      verificado = 1;
      return 1; // Igual a entrar no modo admin
    }
    else if (user.user == 2 && user.senha == 22)
    {
      printf("Bem vindo ao modo user!\n");
      verificado = 1;
      return 2; // Igual a entrar no modo cliente/user
    }
    else
    {
      printf("Login ou senha incorretos, tente novamente!\n");
    }
  }

  return 0;
}

int main()
{
  int checkout = login();
  if (checkout == 1)
  {
    printf("Voce e um admin");
  }
  else
  {
    printf("Voce e um cliente");
  }

  return 0;
}
