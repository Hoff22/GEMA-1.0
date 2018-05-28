#include <bits/stdc++.h>

using namespace std;

#define N 50

long long nck[N + 1][N + 1];

/* O(N^2) Preenche a matriz de n escolhe k. */
void pascal(){
	int i, j;

	// Preenchendo a coluna 0 com 1.
	for (i = 0; i <= N; i++){
		nck[i][0] = 1;
	}

	// Preenchendo os outros valores do triângulo de pascal a partir da recorrência.
	for (i = 1; i <= N; i++){
		for (j = 1; j <= i; j++){
			nck[i][j] = nck[i - 1][j - 1] + nck[i - 1][j];
		}
	}
}

/* O(N^2). */
int main(){
	long long n, k;

	// Pré-calculando o triângulo de pascal até a N-ésima linha.
	pascal();
	
	scanf("%lld%lld", &n, &k);

	// Calculando n choose k.
	printf("%lld\n", nck[n][k]);

	return 0;
}