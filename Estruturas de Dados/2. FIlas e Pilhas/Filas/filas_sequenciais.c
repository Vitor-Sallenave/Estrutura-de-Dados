// Filas Sequenciais
/*
Obs.: Assim como nas filas encadeadas, precisamos utilizar variáveis que
indiquem o início e o fim da lista para que as funções tenham tempo O(1);
*/

# include <stdio.h>


typedef struct Fila{
	int E[10];
	int inicio;
	int fim;
} Fila;

void constroi(Fila*p);

void enfileira(Fila*p, int x);

void exibe(Fila*p);

int desenfileira(Fila*p);

int proximo(Fila*p);


int main(){

	// Construindo
	Fila F;
	F.inicio = 0;
	F.fim = 0;
	
	printf("ENFILEIRA\n");
	int i;
	for (i = 1; i <= 10; i++){
		enfileira(&F, i);
	}
	
	printf("EXIBE\n");
	exibe(&F);
	printf("\n");
	
	printf("DESENFILEIRA\n");
	for (i = 1; i <= 5; i++){
		printf("%d", desenfileira(&F));
		printf("\n");
	}
	
	printf("EXIBE\n");
	exibe(&F);
	printf("\n");
	
	printf("PROXIMO\n");
	printf("%d", proximo(&F));
	printf("\n");

	return 0;
}


void enfileira(Fila*p, int x){
	// Pontos críticos: inserir um novo elemento quando há espaço no vetor;
	// O vetor será interpretado como "circular"
	
	p -> E[p -> fim] = x;
	p -> fim += 1;
}

void exibe(Fila*p){
	int cont;
	
	for(cont = p -> inicio; cont < p -> fim; cont++){
		printf("%d ", p -> E[cont]);
	}
}

int desenfileira(Fila*p){
	int desenfileirado = p -> E[p -> inicio];
	p -> inicio += 1;
	
	return desenfileirado;
}

int proximo(Fila*p){
	return p -> E[p -> inicio];
}


