# include <stdio.h>


void BubbleSort(int v[], int N);


int main(){

	int vetor[] = {7, 2, 9, 1, 4};
	int N = 5; // última posição
	
	BubbleSort(vetor, N);
	
	int k;
	for (k = 0; k <= N; k++){
		printf("%d", vetor[k]);
	}

	return 0;
}


void BubbleSort(int v[], int N){
	if(N != 0){
		BubbleSort(v, N-1);
		
		int i, j, aux;
		
		for(i = 0; i < N; i++){
			for(j = i; j <= N; j++){
				if(v[i] > v[j]){
					aux = v[j];
					v[j] = v[i];
					v[i] = aux;
				}
			}
		}
	}
}

