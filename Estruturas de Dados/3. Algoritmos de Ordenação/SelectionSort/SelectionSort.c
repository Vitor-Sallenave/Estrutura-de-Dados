/* SelectionSort: 
1. Procura sempre o menor valor do array e o posiciona na primeira posição 
OU
2. Procura sempre o maior valor e o posiciona na última posição
*/

// Complexidade: O(N²)

# include <stdio.h>

# define l printf("_____________________\n")

void Imprimir(float vet[], int k);


int main(){
	float vetor1[] = {4.0, 2.0, 8.0, 1.0, 9.0, 5.0, 2.3, 4.5, 6.7, 4.1}, N = 10;
	int i, j, menor;
	float aux;
	
	for (i = 0; i < N-1; i++){
		// Verificação da posição do menor
		menor = i;
		for (j = i+1; j < N; j++){
			if (vetor1[j] < vetor1[menor]){
				menor = j;
			}
		}
		if (vetor1[i] != menor){
			aux = vetor1[i];
			// O primeiro elemento recebe o menor valor
			vetor1[i] = vetor1[menor];
			vetor1[menor] = aux;
		}
	}

	printf("    Lista Ordenada\n");
	l;
	Imprimir(vetor1, 10);
	return 0;
}


void Imprimir(float vet[], int k){
	int n;
	
	for (n = 0; n < k; n++){
		printf("\t%f\n ", vet[n]);
	}
}


