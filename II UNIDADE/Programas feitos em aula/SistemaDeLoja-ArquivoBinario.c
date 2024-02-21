#include <stdio.h>

struct Cliente
{
	char nome[30];
	float compra;
};

typedef struct Cliente Cliente;


void menu(){
	printf("Escolha uma opcao:\n");
	printf("1-Cadastrar\n2-Listar\n3-Sair\n");
	printf("-----------------------\n");
}

void cadastrar(){
	FILE *file = fopen("cliente.b", "ab");
	printf("Informe o nome e o valor da compra:\n");
	Cliente cliente;
	scanf("%s %f", cliente.nome, &cliente.compra);
	fwrite(&cliente, sizeof(Cliente), 1, file);
	fclose(file);
}

void listar(){
	FILE *file = fopen("cliente.b", "rb");
	Cliente cliente;
	while (fread(&cliente, sizeof(Cliente), 1, file))
	{
		printf("%s: %.2f\n", cliente.nome, cliente.compra);
	}
	
	fclose(file);
}

int main(){
	int op;
	menu();
	
	scanf("%d", &op);
	while (op!=3)
	{
		if(op==1){
			cadastrar();
		}else if(op==2){
			listar();
		}
		menu();
		scanf("%d", &op);
	}
	
	return 0;
}

