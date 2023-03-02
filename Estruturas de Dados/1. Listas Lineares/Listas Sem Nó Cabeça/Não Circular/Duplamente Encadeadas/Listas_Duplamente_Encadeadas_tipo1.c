# include <stdio.h>
# include <stdlib.h>

# define l printf("\n_____________________________________________\n")


typedef struct node{
	int elem;
	struct node*prox;
	struct node*ant;
} node;


typedef struct ListaLinear{
	node*inicio;
	int N;
} ListaLinear;


void constroi(ListaLinear*L);

void inserir(ListaLinear*L, int x);

void escrever(ListaLinear*L);

int remover(ListaLinear*L, int x);

int buscar(ListaLinear*L, int x);


int main(){

	l;
	printf("\t\tCONSTROI");
	l;
	ListaLinear L;
	constroi(&L);
	
	printf("\t\tINSERE");
	int i;
	for (i = 1; i < 11; i++){
		inserir(&L, i);
	}
	inserir(&L, 12);
	inserir(&L, 13);
	
	l;
	printf("\t\tEXIBINDO");
	escrever(&L);
	
	l;
	printf("\t\tREMOVE");
	l;
	printf("%d", remover(&L, 3));
	escrever(&L);
	l;
	printf("%d", remover(&L, 11));
	escrever(&L);
	l;
	printf("%d", remover(&L, 13));
	escrever(&L);
	l;
	printf("%d", remover(&L, 1));
	escrever(&L);
	
	// Busca não funciona!
	l;
	printf("Buscar 4: %d\n", buscar(&L, 4));
	printf("Buscar 12: %d\n", buscar(&L, 12));
	//printf("Buscar 1: %d", buscar(&L, 1));
	
	return 0;
}


void constroi(ListaLinear*L){
	L -> inicio = NULL;
	L -> N = 0;
}

void inserir(ListaLinear*L, int x){
	// Pontos críticos: a lista está vazia
	
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	novo -> ant = NULL;
	novo -> prox = L -> inicio;
	
	// Verificando se a lista está vazia
	if (L -> inicio != NULL){
		L -> inicio -> ant = novo;	
	}
	
	L -> inicio = novo;
	
	L -> N += 1;
}

void escrever(ListaLinear*L){
	node*p = L -> inicio;
	
	l;
	while(p != NULL){
		printf("%d ", p -> elem);
		p = p -> prox;
	}
}

int remover(ListaLinear*L, int x){
	// Pontos críticos: 
	// remover o primeiro elemento
	// lista vazia ou não construída
	
	// Verificando se a lista já foi construída ou está vazia
	if (L == NULL || L -> inicio == NULL){
		return 0;
	}
	
	// Percorrendo a lista
	node*p = L -> inicio;
	while(p -> elem != x && p -> prox != NULL){
		p = p -> prox;
	}
	
	// p -> elem pode ser x ou poder ser o último elemento
	if (p -> elem == x){
		// Verificando se é o primeiro elemento (pant == NULL)
		if (p -> ant != NULL){
			p -> ant -> prox = p -> prox;
		} else{
			L -> inicio = p -> prox;
		}
	} else{
		// é o último elemento: o elemento procurado não está na lista
		return 0;
	}
	
	// Verificando se há mais de um elemento na lista
	if (p -> prox != NULL){
		p -> prox -> ant = p -> ant;
	}
	
	free(p);
	L -> N -= 1;
	
	return 1;
}

int buscar(ListaLinear*L, int x){
	node*p = L -> inicio;
	
	while ((p != NULL) && (p -> elem != x)){
		p = p -> prox;
	}
	
	if (p != NULL){
		return 1;
	} else{
		return -1;
	}
}

