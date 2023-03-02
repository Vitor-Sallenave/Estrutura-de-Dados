# include <stdio.h>

void MergeSort(int V[], int inicio, int fim);
void Merge(int vetor[], int inicio, int meio, int fim);

int main(){

	int vetor1[] = {3, 1, 7, 9, 10, 2};
	int vetor2[] = {3, 1, 7, 9, 10, 2};
	int N = 6, n;

	printf("VETOR\n\n");
	for (n = 0; n < N; n++){
		printf("%d ", vetor2[n]);
	}
	
	MergeSort(vetor1, 0, 5);
	
	printf("\n\n");
	printf("VETOR ORDENADO COMPLETO\n\n");
	for (n = 0; n < N; n++){
		printf("%d ", vetor1[n]);
	}
	
	MergeSort(vetor2, 2, 5);
	
	printf("\n\n");
	printf("VETOR ORDENADO PARCIALMENTE\n\n");
	for (n = 0; n < N; n++){
		printf("%d ", vetor2[n]);
	}
	
	return 0;
}

void Merge(int vetor[], int inicio, int meio, int fim){
	int tamanho = fim - inicio + 1;
	int temp[tamanho];
	int i, j, k;
	int p1, p2;
	int fim1 = 0, fim2 = 0;
	
	p1 = inicio;
	p2 = meio + 1;
	
	for (i = 0; i < tamanho; i++){
		// Verificando se as duas partes do vetor chegaram ao fim
		if (fim1 == 0 && fim2 == 0) {
			if (vetor[p1] < vetor[p2]){
				temp[i] = vetor[p1];
				p1 += 1;
			} 
			else{
				temp[i] = vetor[p2];	
				p2 += 1;
			}

			if (p1 > meio)
				fim1 = 1;
			if (p2 > fim)
				fim2 = 1;
		}
		else{
			if (fim1 == 0){
				// A segunda parte do vetor chegou ao fim
				temp[i] = vetor[p1];
				p1++;
			} else{
				// A primeira parte do vetor chegou ao fim
				temp[i] = vetor[p2];
				p2++;
			}	
		}
	}
	
	// Repassando os valores para o vetor original
	for (j = 0, k = inicio; j < tamanho; j++, k++){
		vetor[k] = temp[j];
	}
}


void MergeSort(int V[], int inicio, int fim){
	int meio;
	
	if (inicio < fim){
		meio = (inicio + fim)/2;
		
		MergeSort(V, inicio, meio);
		MergeSort(V, meio + 1, fim);
		Merge(V, inicio, meio, fim);
	}
}







