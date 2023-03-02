# include <stdio.h>
# include <stdlib.h>

typedef struct node{
	int E;
	struct node*prox;
} node;

node* CriaElemento(int);
void InsereInicio(node**, int);
void InsereFim(node**, int);
void ImprimeElemento(node*);
void ImprimeLista(node*);
node* BuscaElemento(node*, int x);
void Libera(node*);
void ExcluiElemento(node**, int x);
void ExcluiPonteiro(node**, node*);
void Destroi(node**);

int main(){

	node * phead = NULL;
	
	int i;
	for (i = 1; i <= 5; i++){
		InsereInicio(&phead, i);
	}
	
	printf("\n_________Inicio_____________\n");
	ImprimeLista(phead);
	printf("\n__________________________\n");
	
	for (i = 6; i <= 10; i++){
		InsereFim(&phead, i);
	}
	
	printf("\n_________Fim________________\n");
	ImprimeLista(phead);
	printf("\n__________________________\n");
	
	printf("\n__________BUSCA_____________\n");
	BuscaElemento(phead, 1);
	BuscaElemento(phead, 10);
	BuscaElemento(phead, 3);
	BuscaElemento(phead, 11);
	printf("\n__________________________\n");
	
	printf("\n_________Exclui E___________\n");
	ExcluiElemento(&phead, 1);
	ExcluiElemento(&phead, 10);
	ExcluiElemento(&phead, 3);
	ExcluiElemento(&phead, 11);
	ImprimeLista(phead);
	printf("\n__________________________\n");
	
	printf("\n_________Exclui P___________\n");
	ExcluiPonteiro(&phead, BuscaElemento(phead, 9));
	ExcluiPonteiro(&phead, BuscaElemento(phead, 4));
	ExcluiPonteiro(&phead, BuscaElemento(phead, 2));
	ExcluiPonteiro(&phead, BuscaElemento(phead, 11));
	ImprimeLista(phead);
	printf("\n__________________________\n");
	
	printf("\n__________Destroi______________\n");
	Destroi(&phead);
	ImprimeLista(phead);
	printf("\n__________________________\n");
	
	return 0;
}


node* CriaElemento(int x){
	node*novo = (node*)malloc(sizeof(node));
	novo -> E = x;
	return novo;
}

void InsereInicio(node**p, int x){
	node*novo = CriaElemento(x);
	novo -> prox = *p;
	*p = novo;
}

void InsereFim(node**p, int x){
	if(*p){
		InsereFim(&((*p) -> prox), x);
	} else{
		node*novo = CriaElemento(x);
		novo -> prox = NULL;
		*p = novo;
	}
}

void ImprimeElemento(node*p){
	if(p){
		printf("%d ", p -> E);
	}
}

void ImprimeLista(node*p){
	if(p){
		ImprimeElemento(p);
		ImprimeLista(p -> prox);
	}
}

node* BuscaElemento(node*p, int x){
	if(p){
		if(p -> E == x){
			printf("Elemento %d encontrado\n", x);
			return p;
		} else{
			return BuscaElemento(p -> prox, x);
		}
	} else{
		printf("O elemento %d nao esta na lista\n", x);
		return NULL;
	}
}

void Libera(node*p){
	free(p);
}

void ExcluiElemento(node**p, int x){
	if(*p){
		if((*p) -> E == x){
			node * aux = *p;
			*p = aux -> prox;
			Libera(aux);
			printf("\nElemento %d excluido\n", x);
		} else{
			ExcluiElemento(&((*p) -> prox), x);
		}
	} else{
		printf("\nO elemento %d nao existe\n", x);
	}
}

void ExcluiPonteiro(node**p, node*n){
	if(*p){
		if((*p) == n){
			*p = n -> prox;
			Libera(n);
			printf("Elemento excluido\n");
		} else{
			ExcluiPonteiro(&((*p) -> prox), n);
		}
	} else{
		printf("\nO elemento nao existe\n");
	}
}

void Destroi(node**p){
	if(*p){
		Destroi(&((*p) -> prox));
		Libera(*p);
		*p = NULL;
	}
}
