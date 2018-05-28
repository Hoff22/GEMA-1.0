#include <bits/stdc++.h>

using namespace std;

#define N 100
#define M 100

long long mat[N][M];

/* O(N * M). */
int main(){
	bool equal, asc, desc;
	int n, m, i, j;

	scanf("%d%d", &n, &m);

	// Lendo a matriz NxM.
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%lld", mat[i] + j);
		}
	}

	for (j = 0; j < m; j++){
		// Dizendo que inicialmente os elementos dessa coluna são iguais, ascendentes e descendentes.
		equal = asc = desc = true;

		// Para cada par de elementos consecutivos nessa coluna.
		for (i = 1; i < n; i++){
			// A coluna continua sendo igual se ela era igual até a última iteração e se o elemento atual for igual ao anterior.
			equal = equal and (mat[i - 1][j] == mat[i][j]);
			// A coluna continua sendo ascendente se ela era ascendente até a última iteração e se o elemento atual for maior que o anterior.
			asc = asc and (mat[i - 1][j] < mat[i][j]);
			// A coluna continua sendo descendente se ela era descendente até a última iteração e se o elemento atual for menor que o anterior.
			desc = desc and (mat[i - 1][j] > mat[i][j]);
		}

		// Se for uma coluna com elementos iguais, ascendentes ou descendentes.
		if (equal or asc or desc){
			printf("S\n");
		}
		else{
			printf("N\n");
		}
	}

	return 0;
}