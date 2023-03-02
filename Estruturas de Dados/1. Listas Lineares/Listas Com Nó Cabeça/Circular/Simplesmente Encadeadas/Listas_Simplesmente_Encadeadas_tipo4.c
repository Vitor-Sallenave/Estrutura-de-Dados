# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int elem;
	struct node*prox;
} node;

typedef struct ListaLinear {
	int N;
	node*inicio;
	node*fim;
} ListaLinear;


void constroi(ListaLinear*L);

void insere(ListaLinear*L, int x);

void escreve(ListaLinear*L);

int remover(ListaLinear*L, int x);


int main(){

	printf("CONSTROI\n");
	ListaLinear L;
	constroi(&L);
	
	printf("INSERE\n");	
	int i;
	for (i = 1; i < 11; i++){
		insere(&L, i);
	}
	
	printf("ESCREVE\n");
	escreve(&L);
	
	printf("REMOVE\n");
	printf("Remove 3: %d\n", remover(&L, 3));
	escreve(&L);
	printf("Remove 1: %d\n", remover(&L, 1));
	escreve(&L);
	printf("Remove 10: %d\n", remover(&L, 10));
	escreve(&L);
	printf("Remove 1: %d\n", remover(&L, 1));
	escreve(&L);

	return 0;
}


void constroi(ListaLinear*L){
	node*head = (node*)malloc(sizeof(node));
	L -> inicio = head; 
	
	head -> prox = NULL;
	L -> fim = NULL;
	L -> N = 0;
}

void insere(ListaLinear*L, int x){
	node*novo = (node*)malloc(sizeof(node));
	node*head = L -> inicio;
	
	novo -> prox = head -> prox;
	novo -> elem = x;
	head -> prox = novo;
	
	// Verificando se a lista possui apenas um elemento
	if (L -> fim == NULL){
		L -> fim = novo;
	}
	L -> fim -> prox = novo;
	
	L -> N += 1;
}

void escreve(ListaLinear*L){
	node*head = L -> inicio;
	
	int cont = L -> N;
	while(cont > 0){
		printf("%d ", head -> prox -> elem);
		head = head -> prox;
		cont -= 1;
	}
	
	printf("\n");
}

int remover(ListaLinear*L, int x){
	node*pant = NULL;
	node*p = L -> inicio -> prox;
	
	int cont = L -> N;
	while(cont > 0 && p -> elem != x){
		pant = p;
		p = p -> prox;
		cont -= 1;
	}
	
	if (p -> elem != x){
		return 0;
	}
	
	if (pant != NULL){
		pant -> prox = p -> prox;
	} else{
		L -> inicio -> prox = p -> prox;
		L -> fim -> prox = p -> prox;
	}
	
	free(p);
	L -> N -= 1;
	
	return 1;
}

