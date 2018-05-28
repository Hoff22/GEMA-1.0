#include <bits/stdc++.h>

using namespace std;

#define N 100000

int v[N];

/* O(N). */
int main(){
	int n, i, i_min, i_max;

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		scanf("%d", v + i);
	}

	// Índices do maior e do menor elemento.
	i_max = i_min = 0; // Dizemos que o primeiro elemento v[0] é, inicialmente, o maior e o menor elemento.

	// Para cada um dos outros elementos.
	for (i = 1; i < n; i++){
		// Se o elemento na posição i for maior que o maior elemento já encontrado.
		if (v[i] > v[i_max]){
			i_max = i; // Atualizando a posição do maior elemento com i.
		}

		// Se o elemento na posição i for menor que o menor elemento já encontrado.
		if (v[i] < v[i_min]){
			i_min = i; // Atualizando a posição do menor elemento com i.
		}
	}

	// Imprimindo a diferença entre o maior e o menor elemento.
	printf("%d\n", v[i_max] - v[i_min]);

	return 0;
}