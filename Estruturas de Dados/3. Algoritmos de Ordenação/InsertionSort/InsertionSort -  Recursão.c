# include <stdio.h>

void InsertionSort(int v[], int N);

int main(){
	int vetor[] = {3, 1, 5, 2, 8, 12, 2, 9, 6, 7};
	int N = 9; // posição do último termo
	int i, j, aux;

	InsertionSort(vetor, N);

	printf("Elementos do vetor: ");
	for (i = 0; i < N; i++){
		printf("%d ", vetor[i]);
	}
	
	return 0;
}

void InsertionSort(int v[], int N){
	if(N != 0){
		InsertionSort(v, N-1);
		
		int k = N, aux;
		while(k > 0 && (v[k-1] > v[k])){
			aux = v[k];
			v[k] = v[k-1];
			v[k-1] = aux;
			k--;
		}
	}
}

