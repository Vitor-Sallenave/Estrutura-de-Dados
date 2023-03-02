// Filas Encadeadas
/*
Obs.: O problema inicial é que as funções não são todas constantes.
Dependendo da ordenção da Fila,
ou enfileirar ou desenfileirar vai ser de complexidade O(N).
Para resolver isso, utiliza-se um ponteiro inicio e um ponteiro fim.
*/

# include <stdio.h>
# include <stdlib.h>


typedef struct node{
	int elem;
	struct node*prox;
} node;

typedef struct Fila{
	node*inicio;
	node*fim;
	int N;
} Fila;

void constroi(Fila*p);

int tamanho(Fila*p);

void enfileira(Fila*p, int x);

void exibe(Fila*p);

int desenfileira(Fila*p);

int proximo(Fila*p);


int main(){

	Fila F;
	constroi(&F);
	
	printf("ENFILEIRA:\n");
	int i;
	for (i = 1; i <= 10; i++){
		enfileira(&F, i);
	}
	
	printf("EXIBE:\n");
	exibe(&F);
	printf("\n");
	
	printf("DESENFILEIRA:\n");
	for (i = 1; i <= 5; i++){
		printf("%d\n", desenfileira(&F));
	}
	
	printf("EXIBE:\n");
	exibe(&F);
	printf("\n");
	
	printf("PROXIMO:\n");
	printf("%d", proximo(&F));

	return 0;
}


void constroi(Fila*p){
	p -> inicio = NULL;
	p -> fim = NULL;
	p -> N = 0;
}

int tamanho(Fila*p){
	return p -> N;
}

void enfileira(Fila*p, int x){
	// Na fila encadeada, é melhor construírmos os nós da esquerda para a direita
	// Ex.: 1, 2, 3
	
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	novo -> prox = NULL;
	
	// Verificando se a fila está vazia
	if (p -> inicio == NULL && p -> fim == NULL){
		p -> inicio = novo;	
	} else{
		p -> fim -> prox = novo;
	}
	p -> fim = novo;
	
	p -> N += 1;
}

void exibe(Fila*p){
	node*pont = p -> inicio;
	
	while(pont != NULL){
		printf("%d ", pont -> elem);
		pont = pont -> prox;
	}
}

int desenfileira(Fila*p){
	int desenfileirado = p -> inicio -> elem;
	p -> inicio = p -> inicio -> prox;
	p -> N -= 1;
	
	return desenfileirado;
}

int proximo(Fila*p){
	return p -> inicio -> elem;
}


