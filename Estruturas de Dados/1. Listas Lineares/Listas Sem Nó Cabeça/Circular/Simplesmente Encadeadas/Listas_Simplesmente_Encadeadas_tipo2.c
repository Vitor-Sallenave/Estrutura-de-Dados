# include <stdio.h>
# include <stdlib.h>

# define l printf("\n___________________________________________\n")

typedef struct node{
	int elem;
	struct node*prox;
} node;

typedef struct ListaLinear{
	int N;
	node*inicio;
	node*fim;
} ListaLinear;

void constroi(ListaLinear*L);

void insere(ListaLinear*L, int x);

void insere_ordenado(ListaLinear*L, int x);

void escreve(ListaLinear*L);

void remover(ListaLinear*L, int x);

int busca(ListaLinear*L, int x);


int main(){

	ListaLinear L;
	constroi(&L);
	
	printf("\t\tCONSTROI");
	l;
	printf("\t\tINSERE");
	int i;
	for (i = 1; i < 11; i++){
		insere(&L, i);
	}
	insere(&L, 12);
	
	l;
	printf("\t\tEXIBE");
	escreve(&L);
	
	l;
	printf("\tINSERE ORDENADAMENTE");
	insere_ordenado(&L, 11);
	escreve(&L);
	insere_ordenado(&L, 13);
	escreve(&L);
	insere_ordenado(&L, 0);
	escreve(&L);
	
	l;
	printf("\t\t REMOVE");
	remover(&L, 1);
	escreve(&L);
	remover(&L, 13);
	escreve(&L);
	remover(&L, 3);
	escreve(&L);
	
	l;
	printf("\t\t BUSCA");
	l;
	printf("1 esta na lista? %d\n", busca(&L, 1));
	printf("12 esta na lista? %d\n", busca(&L, 12));
	printf("0 esta na lista? %d\n", busca(&L, 0));

	return 0;
}


void constroi(ListaLinear*L){
	L -> N = 0;
	L -> inicio = NULL;
	L -> fim = NULL;
}

void insere(ListaLinear*L, int x){
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	novo -> prox = L -> inicio;
	L -> inicio = novo;

	if (L -> fim == NULL){
		L -> fim = novo;
	}
	
	// Conectamos o primeiro elemento inserido com o novo
	L -> fim -> prox = novo;
	
	L -> N += 1;
}

void escreve(ListaLinear*L){
	node*p = L -> inicio;
	
	l;
	int i;
	for(i = 0; i < L -> N; i++){
		printf("%d ", p -> elem);
		p = p -> prox;
	}
}

void insere_ordenado(ListaLinear*L, int x){
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	
	node*p = L -> inicio;
	node*pant = NULL;
	int cont = L -> N;
	while(p -> elem > x &&  cont > 0){
		pant = p;
		p = p -> prox;
		cont -= 1;
	}
	
	if (pant != NULL){
		pant -> prox = novo;
	} else{
		L -> inicio = novo;
	}
	novo -> prox = p;
	
	L -> N += 1;
}

void remover(ListaLinear*L, int x){
	node*p = L -> inicio;
	node*pant = NULL;
	
	while(p -> elem != x){
		pant = p;
		p = p -> prox;
	}
	
	if (pant != NULL){
		pant -> prox = p -> prox;
	} else{
		L -> inicio = p -> prox;
	}
	
	free(p);
	L -> N -= 1;
}

int busca(ListaLinear*L, int x){
	node*p = L -> inicio;
	
	int cont = L -> N;
	while(cont > 0 && p -> elem != x){
		cont -= 1;
		p = p -> prox;
	}
	
	if (p -> elem == x){
		return 1;
	} else{
		return 0;
	}
}







