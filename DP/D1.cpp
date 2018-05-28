#include <bits/stdc++.h>

using namespace std;

#define K 20
#define N 1000000
#define INF 0x3f3f3f3f

string str;
int dp[N + 1][K + 1];
int n;

/* O(N * Log(N)) Retorna o tempo mínimo necessário para terminar a fase, dado que estamos
na posição x e que já pegamos k power ups. Como o número máximo de power ups que podemos pegar
é da ordem de Log(N) a complexidade fica N * Log(N). */
int solve(int x, int k){
	// Se terminou a fase.
	if (x >= n){
		return 0;
	}

	// Se na posição atual houver um buraco.
	if (str[x] == '.'){
		return INF;
	}

	// Se esse estado já foi calculado, retorne seu valor.
	if (dp[x][k] != -1){
		return dp[x][k];
	}

	// Se na posição atual houver um power up, devemos escolher entre pega-lo ou não pega-lo.
	if (str[x] == 'p'){
		return dp[x][k] = min(solve(x + 1, k), solve(x + 1 + (1 << (k + 1)), k + 1)) + 1;
	}

	// Se a posição atual for normal, podemos apenas seguir para a próxima posição.
	return dp[x][k] = solve(x + 1, k) + 1;
}

/* O(N * Log(N)). */
int main(){
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	cin >> str;

	// Se a função retornou infinito, então é impossível terminar a fase.
	cout << (solve(0, 0) >= INF ? -1 : solve(0, 0)) << endl;

	return 0;
}