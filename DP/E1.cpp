#include <bits/stdc++.h>

using namespace std;

#define P 18
#define N 18
#define M 18

long long dp[P + 1][N + 1][M + 1][2];
long long pot[P + 1];
long long x;
int n, m;

/* O(N * M * Log(MAX)) com constante 2 * 10 = 20. Retorna a quantidade de números 
menores ou iguais a x que possuem exatamente n dígitos 4 e m dígitos 7, considerando
que estamos no dígito p com cur_n dígitos 4, cur_m dígitos 7 e nosso número já é
menor que x se lesser for true. */
long long solve(int p, int cur_n, int cur_m, bool lesser){
	int i, d;

	// O número já foi inteiro preenchido, retorna 1 se tivermos exatamente n dígitos 4 e/ou m dígitos 7.
	if (p < 0){
		return cur_n == n or cur_m == m;
	}

	// Se esse estado já foi calculado, retorne seu valor.
	if (dp[p][cur_n][cur_m][lesser] != -1){
		return dp[p][cur_n][cur_m][lesser];
	}

	// Obtendo o dígito máximo permitido para essa posição do número.
	d = lesser ? 9 : (x / pot[p]) % 10; // Se o nosso número já for menor que x, podemos preencher essa posição com qualquer dígito.

	// Inicializando a dp para esse estado.
	dp[p][cur_n][cur_m][lesser] = 0;

	// Para cada dígito possível para essa posição.
	for (i = 0; i <= d; i++){
		// Somando a resposta para a posição p - 1, passando para frente o novo número de dígitos 4,
		// o novo número de dígitos 7 e atualizando o parâmetro lesser, que indica se o nosso número já
		// é menor do que x.
		dp[p][cur_n][cur_m][lesser] += solve(p - 1, cur_n + (i == 4), cur_m + (i == 7), (i < d ? true : lesser));
	}

	return dp[p][cur_n][cur_m][lesser];
}

/* O(N * M * Log(MAX)) com constante 2 * 2 * 10 = 40. */
int main(){
	long long ans, l, r;
	int i;

	// Pré-calculando as potências de 10.
	pot[0] = 1;

	for (i = 1; i <= N; i++){
		pot[i] = pot[i - 1] * 10;
	}

	scanf("%d%d", &n, &m);
	scanf("%lld%lld", &l, &r);

	// Somando a quantidade de números que dão azar no intervalo [0, r] que satisfazem a restrição.
	memset(dp, -1, sizeof(dp));
	x = r;
	ans = solve(P, 0, 0, false);

	// Subtraindo a quantidade de números que dão azar no intervalo [0, l - 1] que satisfazem a restrição.
	memset(dp, -1, sizeof(dp));
	x = l - 1;
	ans -= solve(P, 0, 0, false);

	printf("%lld\n", ans);

	return 0;
}