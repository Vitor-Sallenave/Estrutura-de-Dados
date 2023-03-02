// PILHAS SEQUENCIAIS
// Obs.: as funções empilha, desempilha e topo são constantes O(1)

# include <stdio.h>


typedef struct Pilha{
	int E[10];
	int N;
} Pilha;

void empilha(Pilha*p, int x);

void exibe(Pilha*p);

int tamanho(Pilha*p);

int desempilha(Pilha*p);

int topo(Pilha*p);


int main(){
	
	// Construindo a pilha
	Pilha P;
	P.N = 0;
	
	printf("EMPILHA:\n");
	int i;
	for (i = 0; i < 10; i++){
		empilha(&P, i);
	}
	
	printf("EXIBE:\n");
	exibe(&P);
	printf("\n");
	
	printf("TAMANHO:\n");
	printf("%d", tamanho(&P));
	printf("\n");
	
	printf("DESEMPILHA:\n");
	for (i = 0; i < 5; i++){
		printf("%d\n", desempilha(&P));
	}
	
	printf("EXIBE:\n");
	exibe(&P);
	printf("\n");
	
	printf("TOPO:\n");
	printf("%d", topo(&P));

	return 0;
}


void empilha(Pilha*p, int x){
	p -> E[p -> N] = x;
	p -> N += 1;
}

void exibe(Pilha*p){
	int cont = p -> N;
	
	while (cont > 0){
		printf("%d ", p -> E[cont - 1]);
		cont -= 1;
	}
}

int tamanho(Pilha*p){
	return p -> N;
}

int desempilha(Pilha*p){
	int desempilhado = p -> E[p -> N - 1];
	p -> N -= 1;
	
	return desempilhado;
}

int topo(Pilha*p){
	return p -> E[ p -> N - 1];
}

