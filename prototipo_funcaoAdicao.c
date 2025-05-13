
#include <stdio.h>

typedef struct tarefa *apontador;

typedef struct tarefa {
	int id;
	char titulo[100];
	char descricao[200];
	char data[11];
	int prioridade;
	int status;
}task;

int main()//Possivel esqueleto da funcao, sujeito a mudancas (provavelmente sera alterado)
{
	char opcao;
	int while_1 = 1;

	printf("**************Bem vindo a lista de tarefas!**************\n");
	printf("1 - Adicionar tarefa.\n");
	printf("2 - Visualizar tarefas.\n");
	printf("3 - Sair.\n");
	scanf("%c", &opcao);

	while(while_1 == 1) { //while_1
		switch (opcao) {
		case '1':
            while_1 = 0;
			break;
		case '2':
            while_1 = 0;
			break;
		case '3':
			printf("Até logo!");
			while_1 = 0;
			break;
		default:
			printf("Digite um opcao valida!");
		}
	}
	return 0;
}

void adicionarTarefa(){
    
    char aux_char[200];
    int aux_int;
    int confirma = 1;
    
    printf("Qual tarefa deseja adicionar?\n");
    scanf("%s", &aux_char);
    
    
}