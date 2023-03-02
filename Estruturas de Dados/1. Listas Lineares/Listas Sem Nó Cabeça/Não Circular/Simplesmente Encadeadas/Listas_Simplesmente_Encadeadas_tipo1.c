# include <stdio.h>
# include <stdlib.h>

# define l printf("\n_____________________________________________\n")


typedef struct node{
	int elem;
	struct node*prox;
} node;


typedef struct ListaLinear{
	int N; 
	node*inicio;
	
} ListaLinear;


void criar_lista(ListaLinear*L);

void inserir(ListaLinear*L, int x);

void inserir_ordenado(ListaLinear*L, int x);

void escrever(ListaLinear*L);

void remover(ListaLinear*L, int x);

int Busca(ListaLinear*L, int x);


int main(){

	l;
	printf("\tCRIANDO A LISTA LINEAR");
	l;
	ListaLinear L;
	criar_lista(&L);
	
	printf("\t\tINSERINDO");
	l;
	int i = 0;
	for (i = 1; i < 11; i++){
		inserir(&L, i);
	}
	inserir(&L, 12);
	
	printf("\t\tEXIBINDO");
	escrever(&L);
	
	l;
	printf("\tINSERINDO ORDENADAMENTE");
	inserir_ordenado(&L, 11);
	escrever(&L);
	inserir_ordenado(&L, 13);
	escrever(&L);
	
	l;
	printf("\t\tREMOVENDO");
	remover(&L, 8);
	escrever(&L);
	remover(&L, 13);
	escrever(&L);
	remover(&L, 1);
	escrever(&L);
	
	l;
	printf("\t\tBUSCANDO");
	l;
	printf("9 esta na lista? %d\n", Busca(&L, 9));
	printf("10 esta na lista? %d\n", Busca(&L, 10));
	printf("1 esta na lista? %d", Busca(&L, 1));
	l;

	return 0;
}


void criar_lista(ListaLinear*L){
	L -> inicio = NULL;
	L -> N = 0;
}

void inserir(ListaLinear*L, int x){
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	novo -> prox = L -> inicio;
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

void remover(ListaLinear*L, int x){
	// Pontos críticos: remoção do primeiro elemento
	
	node*pant = NULL;
	node*p = L -> inicio;
	
	while(p -> elem != x){
		pant = p;
		p = p -> prox;
	}
	
	if (pant != NULL){
		pant -> prox = p -> prox;
	} else{
		L -> inicio = p -> prox;
	}
	
	L -> N -= 1;
}

int Busca(ListaLinear*L, int x){
	// Pontos críticos: busca do último elemento
	
	node*p = L -> inicio;
	
	// Busca no máximo até o final
	while((p -> elem != x) && (p -> prox != NULL)){
		p = p -> prox;
	}
	
	if (p -> prox == NULL){
		// Caso chegue até o final, não encontrou x
		return 0;
	} else{
		return 1;
	}
}

void inserir_ordenado(ListaLinear*L, int x){
	// Pontos críticos: inserção na primeira posição
	
	node*novo = (node*)malloc(sizeof(node));
	novo -> elem = x;
	
	// Procurando um elemento menor que x
	node*p = L -> inicio;
	node*pant = NULL;
	while(p -> elem > x){
		pant = p;
		p = p -> prox;
	}
	
	// Verificando se é ou não a primeira posição
	if (pant != NULL){
		pant -> prox = novo;
	} else{
		L -> inicio = novo;
	}
	novo -> prox = p;
	
	L -> N += 1;
}

