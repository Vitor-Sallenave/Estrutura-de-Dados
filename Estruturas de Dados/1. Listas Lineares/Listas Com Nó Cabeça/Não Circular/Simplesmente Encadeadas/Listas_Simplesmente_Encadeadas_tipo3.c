# include <stdio.h>
# include <stdlib.h>

# define l printf("\n_______________________________________________\n")

typedef struct node{
	int elem;
	struct node*prox;
} node;


typedef struct ListaLinear{
	int N;
	node*inicio;
} ListaLinear;


void constroi(ListaLinear*L);

void insere(ListaLinear*L, int x);

void escreve(ListaLinear*L);

void remover(ListaLinear*L, int x);


int main(){

	ListaLinear L;
	constroi(&L);
	
	l;
	printf("\t\tINSERE");
	int i;
	for (i = 1; i < 11; i++){
		insere(&L, i);
	}
	insere(&L, 12);
	
	l;
	printf("\t\tESCREVE");
	escreve(&L);
	
	l;
	printf("\t\tREMOVE");
	remover(&L, 3);
	escreve(&L);
	remover(&L, 12);
	escreve(&L);
	remover(&L, 1);
	escreve(&L);

	return 0;
}


void constroi(ListaLinear*L){
	// Construindo a cabeça
	node*head = (node*)malloc(sizeof(node));
	head -> prox = NULL;
	L -> inicio = head;
	L -> N = 0;
}

void insere(ListaLinear*L, int x){
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	
	node*head = L -> inicio;
	novo -> prox = head -> prox;
	head -> prox = novo;

	L -> N += 1;
}

void escreve(ListaLinear*L){
	node*p = L -> inicio -> prox;
	
	l;
	while(p != NULL){
		printf("%d ", p -> elem);
		p = p -> prox;
	}
}

void remover(ListaLinear*L, int x){
	node*pant = NULL;
	node*p = L -> inicio -> prox;
	
	while(p -> elem != x){
		pant = p;
		p = p -> prox;
	}
	
	if (pant != NULL){
		pant -> prox = p -> prox;
	} else{
		L -> inicio -> prox = p -> prox;
	}
	
	free(p);
	L -> N -= 1;
}




