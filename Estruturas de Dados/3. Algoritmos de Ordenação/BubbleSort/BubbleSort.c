/* BubbleSort: 
A cada itera��o o maior elemento vai se juntando ao final do vetor.
Diferente do SelectionSort,o m�todo bolha modifica as posi��es do 
vetor a cada itera��o.
 */
 
// Complexidade: O(N�)


# include <stdio.h>
# include <stdbool.h>


int main(){

	int vetor1[] = {4, 1, 7, 2, 8, 9, 3};
	int vetor2[] = {5, 2, 1, 7, 8, 3};
	int i, j, aux;
	bool mudou = 1;

	for (i = 0; i < 7; i++){
		for (j = 0; j < 6; j++){
			if (vetor1[j] > vetor1[j+1]){
				// Troca de valores
				aux = vetor1[j+1];
				vetor1[j+1] = vetor1[j];
				vetor1[j] = aux;
			}
		}
	}
	
	// BubbleSort com parada
	int ultimo = 5;
	
	do{
		mudou = 0;
		for (j = 0; j < ultimo; j++){
			if (vetor2[j] > vetor2[j+1]){
				aux = vetor2[j+1];
				vetor2[j+1] = vetor2[j];
				vetor2[j] = aux;	
				mudou = 1;		
			}			
		}
		ultimo--;
	} while(mudou);
	
	
	printf("Elementos do vetor: ");
	for (i = 0; i < 7; i++){
		printf("%d ", vetor1[i]);
	}
		
	printf("\nElementos do vetor com codigo de parada: ");
	for (i = 0; i < 6; i++){
		printf("%d ", vetor2[i]);
	}
	
	return 0;
}

