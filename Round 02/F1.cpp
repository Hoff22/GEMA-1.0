#include <bits/stdc++.h>

using namespace std;

#define N 5000

int dp[N + 1][N + 1];
int a[N + 1];
int n;

/* O(N^2) Retorna o tamanho da Longest Increasing Subsequence a partir de i,
considerando que o último elemento que pegamos é o a[j]. */
int solve(int i, int j){
	// Caso base.
	if (i > n){
		return 0;
	}

	// Se esse estado já foi calculado, retorne o seu valor.
	if (dp[i][j] != -1){
		return dp[i][j];
	}

	// Se puder pegar o valor atual a[i].
	if (a[j] <= a[i]){
		// Retornando o máximo entre pegar e não pegar a[i].
		return dp[i][j] = max(solve(i + 1, j), 1 + solve(i + 1, i));
	}

	// Ignorando o valor a[i] atual pois não podemos pega-lo.
	return dp[i][j] = solve(i + 1, j);
}

/* O(N^2). */
int main(){
	int i;

	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);

	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
	}

	// A resposta será N - Longest Increasing Subsequence, pois devemos manter a Longest Increasing Subsequence
	// e apenas alterar os valores que não pertencem a Longest Increasing Subsequence.
	printf("%d\n", n - solve(1, 0));

	return 0;
}