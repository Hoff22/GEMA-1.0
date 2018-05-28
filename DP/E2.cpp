#include <bits/stdc++.h>

using namespace std;

#define P 18
#define N 18
#define M 18

long long dp[P + 2][N + 2][M + 2][2];
long long pot[P + 1];
int n, m;

/* O(N * M * Log(MAX)) com constante 2 * 10 = 20. Retorna a quantidade de números 
menores ou iguais a x que possuem exatamente n dígitos 4 e m dígitos 7. */
long long solve(long long x){
	int p, d, i, j, k;

	memset(dp, 0, sizeof(dp));

	// Inicializando a DP.
	for (i = N; i >= 0; i--){
		for (j = M; j >= 0; j--){
			dp[0][i][j][false] = dp[0][i][j][true] = (i == n or j == m);
		}
	}

	// Calculando todos os estados da DP.
	for (p = 1; p <= P + 1; p++){
		for (i = N; i >= 0; i--){
			for (j = M; j >= 0; j--){
				// Extraindo o dígito atual.
				d = (x / pot[p - 1]) % 10;

				// Nosso número pode já ser menor que x ou não para esses dígitos.
				for (k = 0; k <= d; k++){
					dp[p][i][j][false] += dp[p - 1][i + (k == 4)][j + (k == 7)][k < d];
					dp[p][i][j][true] += dp[p - 1][i + (k == 4)][j + (k == 7)][true];
				}

				// Nosso número deve já ser menor que x para esses dígitos.
				for (; k <= 9; k++){
					dp[p][i][j][true] += dp[p - 1][i + (k == 4)][j + (k == 7)][true];
				}
			}
		}
	}

	return dp[P + 1][0][0][false];
}

/* O(N * M * Log(MAX)) com constante 2 * 2 * 10 = 40. */
int main(){
	long long l, r;
	int i;

	// Pré-calculando as potências de 10.
	pot[0] = 1;

	for (i = 1; i <= N; i++){
		pot[i] = pot[i - 1] * 10;
	}

	scanf("%d%d", &n, &m);
	scanf("%lld%lld", &l, &r);

	printf("%lld\n", solve(r) - solve(l - 1));

	return 0;
}