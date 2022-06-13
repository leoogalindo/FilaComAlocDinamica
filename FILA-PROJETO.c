#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct FILA {
	int valor;
	struct FILA *proximo;
};

struct FILA *inicio;
struct FILA *fim;

void filaVazia (void);
char menuOpcoes (void);
void admin (char tecla);
int adicionaFila (void);
int consultaFila (void);
int removeFila (void);
int pesquisa (int valor);
int removeFilaPorElemento (void);


void filaVazia (void){
	struct FILA *aux;
	aux = (struct FILA*) malloc (sizeof(struct FILA));
	inicio = aux;
	fim = inicio;
}

char menuOpcoes (void)
{
	char opcao;
	system("cls");
	printf("\n _____________ GERENCIAMENTO FILA________________\n");
    printf("\n 1- Adicionar na fila");
    printf("\n 2- Remover fila normalmente");
    printf("\n 3- Remover fila por elemento");
    printf("\n 4- Consultar fila");
    printf("\n 5- Sair");
    printf("\n ________________________________________________");
    printf("\n Escolha: ");
    fflush(stdin);
    opcao = getche();
    return opcao; 
}

void admin (char tecla)
{
	switch(tecla)
	{
		case '1': adicionaFila();
		break;
		
		case '2': removeFila();
		break;
		
		case '3': removeFilaPorElemento();
		break;
		
		case '4': consultaFila();
		break;
		
		case '5': exit(0);
		
		default: printf("\n Opção inválida!!!!");
		
		getch();
	}
}

int adicionaFila (void){
	struct FILA *aux;
	aux = (struct FILA*) malloc (sizeof(struct FILA));
	int opc, valor;
	
	printf("\n Insira o valor a ser adicionado: ");
	fflush(stdin);
	scanf("%d", &valor);
	
	aux->valor = valor;
	fim->proximo = aux;
	fim = fim->proximo;
	aux->proximo = inicio;
	
	printf("\n Elemento adicionado: [%d]", valor);
	getch();	
}

int consultaFila (void){
	struct FILA *aux;
	aux = inicio->proximo;
	printf("\n ELEMENTOS NA FILA: ");
	
	while(aux != inicio){
		printf("[%d]", aux->valor);
		aux = aux->proximo;
	}
	
	getch();
}

int removeFila (void){
	struct FILA *aux;
	aux = inicio->proximo;
	printf("\n -----------REMOVENDO NORMALMENTE-----------");
		
	inicio->proximo = inicio->proximo->proximo;
	
	printf("\n Elemento [%d] removido ", aux->valor);
		
	getch();
}

int pesquisa (int valor){
	struct FILA *aux;
	int flag;
	aux = inicio->proximo;
	while(aux != inicio){
		if(aux->valor == valor){
			flag = 1;
			aux = inicio;
		} else {
			aux = aux->proximo;
			
		}
	}
	
	return flag;
	getch();
}

int removeFilaPorElemento (void){
	struct FILA *aux;
	struct FILA *sinal;
	int valor, flag;
	
	aux = inicio->proximo;
	sinal = inicio;
	
	consultaFila();
	
	printf("\n Informe o elemento a ser removido: ");
	fflush(stdin);
	scanf("%d", &valor);
	
	flag = pesquisa(valor);
	
	if(flag == 1){
		while(aux != NULL){
			if(aux->valor == valor){
				printf("\n Item removido: %d", valor);
				sinal->proximo = aux->proximo;
				aux = NULL;
				getch();
			} else {
				aux = aux->proximo;
				sinal = sinal->proximo;
			}
		}
	} else {
		printf("\n Elemento %d não encontrado na Fila", valor);
		getch();
	}
	
}

int main (){
	char opc;
	setlocale(LC_ALL, "");
	filaVazia();
	do{
        opc = menuOpcoes();              
        admin(opc);              
    }while(opc != '5');
	
	getch();	
	return 0;
}
