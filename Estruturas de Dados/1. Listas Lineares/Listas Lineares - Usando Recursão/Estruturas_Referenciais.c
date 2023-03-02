# include <stdio.h>
# include <stdlib.h>

typedef struct coord{
	short x, y;
	struct coord * prox;
} coord;

coord * CriaElemento(short x, short y);
void InsereInicio(coord ** p, short x, short y);
void InsereFim(coord ** p, short x, short y);
void InsereOrdenado(coord ** p, short x, short y);
void ImprimeElemento(coord * p);
void ImprimeLista(coord * p);
coord* BuscaCoord(coord * p, short x, short y);
void Libera(coord * p);
void ExcluiElementoCoord(coord ** p, short x, short y);
void ExcluiElementoPonteiro(coord ** p, coord * c);
void LimparLista(coord ** p);

// TODO:
// Inserir Ordenado
// Ordenar uma lista encadeada


int main(){

	// Criando
	coord * phead = NULL;
	
	// Inserindo
	InsereInicio(&phead, 7, 7);
	InsereInicio(&phead, 4, 4);
	InsereInicio(&phead, 2, 2);
	InsereInicio(&phead, 1, 1);
	
	// Imprimindo
	ImprimeLista(phead);
	
	// Buscando pelas coordenadas
	printf("Busca: ");
	ImprimeElemento(BuscaCoord(phead, 1, 1));
	
	// Removendo
	ExcluiElementoCoord(&phead, -1, -1);
	ExcluiElementoCoord(&phead, -3, -3);
	ExcluiElementoPonteiro(&phead, BuscaCoord(phead, 2, 2));
	printf("\n");
	ImprimeLista(phead);
	
	/* Insere Ordenado - Crescente
	InsereOrdenado(&phead, 6, 6);
	InsereOrdenado(&phead, 4, 4);
	InsereOrdenado(&phead, -3, -3);
	InsereOrdenado(&phead, 10, 10); */
	
	// Excluindo Lista
	LimparLista(&phead);
	ImprimeLista(phead);
	
	return 0;
}


coord * CriaElemento(short x, short y){
	coord * novo = (coord*)malloc(sizeof(coord));
	novo -> x = x;
	novo -> y = y;
	return novo;
}
 
void InsereInicio(coord ** p, short x, short y){
	coord*novo = CriaElemento(x, y);
	novo -> prox = *p;
	*p = novo;
}

void InsereFim(coord ** p, short x, short y){
	if(!*p){
		coord * novo = CriaElemento(x, y);
		novo -> prox = NULL;
		*p = novo;
	} else{
		InsereFim(&((*p) -> prox), x, y);
	}
}

void InsereOrdenado(coord ** p, short x, short y){
	coord * aux2 = *p; // phead
	
	if(aux2 -> x > x && aux2 -> y > y){
		InsereInicio(p, x, y);
	} else if(!aux2){
		InsereFim(p, x, y);
	} else{
		while(aux2 -> prox && aux2 -> prox -> x < x && aux2 -> prox -> y < y){
			aux2 = aux2 -> prox;
		}
		coord * novo = CriaElemento(x, y);
		novo -> prox = aux2 -> prox;
		aux2 -> prox = novo;
	}
}

void ImprimeElemento(coord * e){
	if(e){
		printf("x: %d, y: %d\n", e -> x, e -> y);
	}
}

void ImprimeLista(coord * p){
	if(!p){
		printf("\n\n--- Fim da Lista ---\n\n");
	} else{
		ImprimeElemento(p);
		ImprimeLista(p -> prox);
	}
}

coord* BuscaCoord(coord * p, short x, short y){
	if(!p){
		return NULL;
	} else{
		if(p -> x == x && p -> y == y){
			return p;
		} else{
			return BuscaCoord(p -> prox, x, y);
		}
	}
}
 
void Libera(coord * p){
	free(p);
}

void ExcluiElementoCoord(coord ** p, short x, short y){
	if(*p){
		if((*p) -> x == x && (*p) -> y == y){
			coord * e = *p;
			*p = e -> prox;
			Libera(e);
			printf("\nElemento (%d, %d) excluido\n", x, y);
		} else{
			ExcluiElementoCoord(&((*p) -> prox), x, y);
		}
	} else{
		printf("\nO elemento (%d, %d) nao existe\n", x, y);
	}	
}

void ExcluiElementoPonteiro(coord ** p, coord * c){
	if(*p){
		if(*p == c){
			*p = c -> prox;
			int x = c -> x, y = c -> y;
			Libera(c);
			printf("\nElemento (%d, %d) excluido\n", x, y);
		} else{
			ExcluiElementoPonteiro(&((*p) -> prox), c);
		}
	} else{
		printf("\nElemento inexistente\n");
	}
}

void LimparLista(coord ** p){
	if(*p){
		LimparLista(&((*p) -> prox));
		Libera(*p);
		*p = NULL;
	}
}
