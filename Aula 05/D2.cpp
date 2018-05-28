#include <bits/stdc++.h>

using namespace std;

#define N 10000

bool dp[N + 1];
bool seen[N + 1];
int m;

/* O(N * M). Retorna true se n blocos for uma posição vencedora. */
bool solve(int n){
	int i;

	// Se não tiver nenhum bloco a posição atual é perdedora.
	if (n == 0){
		return false;
	}

	// Se já soubermos o resultado para essa posição, apenas o retornamos.
	if (seen[n]){
		return dp[n];
	}

	// Marcamos essa posição como visitada.
	seen[n] = true;

	// Tentamos remover qualquer número de blocos possível.
	for (i = 1; i <= min(n, m); i++){
		// Se alguma remoção fizer com que o outro jogador esteja numa posição perdedora
		// então a posição atual é vencedora.
		if (!solve(n - i)){
			return dp[n] = true;
		}
	}

	// Se a posição atual não conseguir remover um número de blocos de forma que o outro jogador
	// esteja numa perdedora então a posição atual é perdedora.
	return dp[n] = false;
}

/* O(N * M). */
int main(){
	int n, i;

	scanf("%d%d", &n, &m);

	// Para cada possível primeira jogada.
	for (i = 1; i <= min(n, m); i++){
		// Se ao retirar i blocos o outro jogador perde.
		if (!solve(n - i)){
			break;
		}
	}

	// Checando se o break ocorreu.
	if (i <= min(n, m)){
		printf("O Loppa vai mandar bem\n");
		printf("%d\n", i);
	}
	else{
		printf("O Loppa vai ficar pistola\n");
		printf("0\n");
	}
	
	return 0;
}