// PILHAS ENCADEADAS
// Obs.: as funções empilha, desempilha e topo são constantes O(1)

# include <stdio.h>
# include <stdlib.h>


typedef struct node{
	int elem;
	struct node*prox;
} node;

typedef struct Pilha{
	int N;
	node*topo;
} Pilha;

void constroi(Pilha*p);

int tamanho(Pilha*p);

void empilha(Pilha*p, int x);

void exibe(Pilha*p);

int desempilha(Pilha*p);

int topo(Pilha*p);


int main(){

	Pilha P;
	constroi(&P);

	printf("EMPILHANDO\n");
	int i;
	for (i = 1; i <= 10; i++){
		empilha(&P, i);
	}
	
	printf("EXIBE\n");
	exibe(&P);
	
	printf("TAMANHO\n");
	printf("%d", tamanho(&P));
	printf("\n");

	printf("DESEMPILHA");
	printf("\n");
	for (i = 1; i <= 5; i++){
		printf("%d", desempilha(&P));
		printf("\n");
	}
	
	printf("EXIBE\n");
	exibe(&P);

	printf("TOPO\n");
	printf("%d", topo(&P));

	return 0;
}


void constroi(Pilha*p){
	p -> topo = NULL;
	p -> N = 0;
}

int tamanho(Pilha*p){
	return p -> N;
}

void empilha(Pilha*p, int x){
	// Na pilha, é melhor construírmos os nós da direita para esquerda
	// Ex.: 3, 2, 1
	
	node*novo = (node*)malloc(sizeof(node));
	
	novo -> elem = x;
	novo -> prox = p -> topo;
	p -> topo = novo;
	p -> N += 1;
}

void exibe(Pilha*p){
	node*pont = p -> topo;
	
	while(pont != NULL){
		printf("%d ", pont -> elem);
		pont = pont -> prox;
	}
	printf("\n");
}

int desempilha(Pilha*p){
	int desempilhado = p -> topo -> elem;
	p -> topo = p -> topo -> prox;
	p -> N -= 1;
	
	return desempilhado;
}

int topo(Pilha*p){
	return p -> topo -> elem;
}


