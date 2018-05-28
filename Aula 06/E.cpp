#include <bits/stdc++.h>

using namespace std;

#define N 5000

int a[N + 1];
int sum[N + 1];
long long dp[N + 1][N + 1];

/* O(N^2) Retorna o número de subarrays entre l e r que tenham soma 0. */
long long solve(int l, int r){
	// Se os índices se cruzarem a resposta é 0.
	// (se l == r a resposta também é 0, pois os elementos do vetor só podem ser -1 ou 1).
	if (l > r){
		return 0;
	}

	// Caso a resposta para o intervalo [l, r] já tenha sido computada.
	if (dp[l][r] != -1){
		return dp[l][r];
	}

	// A resposta para o intervalo [l, r] é: [l + 1, r] + [l, r - 1] - [l + 1, r - 1] (Princípio da Inclusão-Exclusão).
	// + 1 se a soma do intervalo [l, r] for 0.
	return dp[l][r] = (sum[r] - sum[l - 1] == 0) + solve(l + 1, r) + solve(l, r - 1) - solve(l + 1, r - 1);
}

/* O(Q + N^2). */
int main(){
	int n, q, l, r, i;

	// Inicializando a dp.
	memset(dp, -1, sizeof(dp));

	scanf("%d%d", &n, &q);

	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
	}

	// Fazendo um vetor de soma acumulada dos valores.
	for (i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + a[i];
	}

	// Para cada query.
	for (i = 1; i <= q; i++){
		scanf("%d%d", &l, &r);

		printf("%lld\n", solve(l, r));
	}

	return 0;
}