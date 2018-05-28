#include <bits/stdc++.h>

using namespace std;

#define N 100
#define MOD 1000000007

long long dp[N + 1][N + 1][N + 1];

/* O(N^3) Retorna o número de formas de ganhar o jogo a partir das torres (a, b, c). */
long long solve(int a, int b, int c){
	// Se alguma torre tiver tamanho negativo significa que uma torre maior foi atirada em uma torre menor, ou seja, jogada inválida.
	if (a < 0 or b < 0 or c < 0){
		return 0;
	}

	// Se alguma torre tiver tamanho 0.
	if (a == 0 or b == 0 or c == 0){
		return 1;
	}

	// Se esse estado já foi calculado, retorne seu valor.
	if (dp[a][b][c] != -1){
		return dp[a][b][c];
	}

	// Atirando as torres de todas as maneiras possíveis.
	return dp[a][b][c] = (solve(a, b - a, c) + solve(a, b, c - a) + solve(a - b, b, c) + solve(a, b, c - b) + solve(a - c, b, c) + solve(a, b - c, c)) % MOD;
}

/* O(N^3). */
int main(){
	int a, b, c;

	memset(dp, -1, sizeof(dp));

	scanf("%d%d%d", &a, &b, &c);

	printf("%lld\n", solve(a, b, c));

	return 0;
}