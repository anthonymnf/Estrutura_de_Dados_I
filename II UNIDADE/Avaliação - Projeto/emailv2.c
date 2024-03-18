#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
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
