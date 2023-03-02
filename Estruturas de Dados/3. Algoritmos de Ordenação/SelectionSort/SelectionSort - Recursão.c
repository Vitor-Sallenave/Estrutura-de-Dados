# include <stdio.h>


void SelectionSort(float v[], int N);


int main(){
	float vetor[] = {4.0, 2.0, 8.0, 1.0, 9.3, 5.0, 2.3, 4.5, 6.7, 4.1};
	int N = 9; // última posição
	
	SelectionSort(vetor, N);
	
	int cont;
	for (cont = 0; cont <= N; cont++){
		printf("%f\n", vetor[cont]);
	}

	return 0;
}


void SelectionSort(float v[], int N){
	if(N != 0){
		int i, maior = 0;
		float aux;
		
		for(i = 1; i <= N; i++){
			if(v[i] > v[maior]){
				maior = i;
			}
		}
		
		aux = v[N];
		v[N] = v[maior];
		v[maior] = aux;
		
		SelectionSort(v, N-1);
	}
}
