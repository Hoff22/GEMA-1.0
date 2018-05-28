#include <bits/stdc++.h>

using namespace std;

#define N 50
#define K 10

long long dp[N + 1][K + 1];

/* O(N * K) Retorna n escolhe k. */
long long solve(long long n, long long k){
	// Casos base.
	if (k == 0 or k == n){
		return 1;
	}

	// Se esse estado já foi calculado, retornamos seu valor.
	if (dp[n][k] != -1){
		return dp[n][k];
	}

	// Calculando n escolhe k pela recorrência.
	return dp[n][k] = solve(n - 1, k - 1) + solve(n - 1, k);
}

/* O(N * K). */
int main(){
	long long n, k;

	// Inicializando os estados como não calculados.
	memset(dp, -1, sizeof(dp));
	
	scanf("%lld%lld", &n, &k);

	// Calculando n choose k.
	printf("%lld\n", solve(n, k));

	return 0;
}