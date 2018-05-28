#include <bits/stdc++.h>

using namespace std;

#define N 100
#define MOD 1000000007

int dp[N + 1][N + 1][N + 1];

/* O(N^3). */
int main(){
	int a, b, c, i, j, k;

	scanf("%d%d%d", &a, &b, &c);

	// Inicializando a DP.
	for (i = 0; i <= a; i++){
		for (j = 0; j <= b; j++){
			dp[i][j][0] = 1;
		}
	}

	for (i = 0; i <= a; i++){
		for (k = 0; k <= c; k++){
			dp[i][0][k] = 1;
		}
	}

	for (j = 0; j <= b; j++){
		for (k = 0; k <= c; k++){
			dp[0][j][k] = 1;
		}
	}

	// Calculando todos os estados.
	for (i = 1; i <= a; i++){
		for (j = 1; j <= b; j++){
			for (k = 1; k <= c; k++){
				if (i <= j){ // Podemos atirar a torre de tamanho i na torre de tamanho j.
					dp[i][j][k] = (dp[i][j][k] + dp[i][j - i][k]) % MOD;
				}

				if (i <= k){ // Podemos atirar a torre de tamanho i na torre de tamanho k.
					dp[i][j][k] = (dp[i][j][k] + dp[i][j][k - i]) % MOD;
				}

				if (j <= i){ // Podemos atirar a torre de tamanho j na torre de tamanho i.
					dp[i][j][k] = (dp[i][j][k] + dp[i - j][j][k]) % MOD;
				}

				if (j <= k){ // Podemos atirar a torre de tamanho j na torre de tamanho k.
					dp[i][j][k] = (dp[i][j][k] + dp[i][j][k - j]) % MOD;
				}

				if (k <= i){ // Podemos atirar a torre de tamanho k na torre de tamanho i.
					dp[i][j][k] = (dp[i][j][k] + dp[i - k][j][k]) % MOD;
				}

				if (k <= j){ // Podemos atirar a torre de tamanho k na torre de tamanho j.
					dp[i][j][k] = (dp[i][j][k] + dp[i][j - k][k]) % MOD;
				}
			}
		}
	}

	printf("%d\n", dp[a][b][c]);

	return 0;
}