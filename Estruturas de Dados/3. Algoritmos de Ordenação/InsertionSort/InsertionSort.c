// InsertionSort: move os elementos maiores que o elemento em análise para frente

# include <stdio.h>

int main(){
	int vetor[] = {3, 1, 5, 2, 8, 12, 2, 9, 6, 7}, N = 10;
	int i, j, aux;

	for (i = 1; i < N; i++){
		aux = vetor[i];
		for (j = i; (j > 0) && (vetor[j-1] > aux); j--){
			vetor[j] = vetor[j-1];
		}
		vetor[j] = aux;
	}
	
	printf("Elementos do vetor: ");
	for (i = 0; i < N; i++){
		printf("%d ", vetor[i]);
	}

	return 0;
}

