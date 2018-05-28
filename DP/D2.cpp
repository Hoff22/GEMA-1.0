#include <bits/stdc++.h>

using namespace std;

#define K 20
#define N 1000000
#define INF 0x3f3f3f3f

int dp[N + 1][K + 1];

/* O(N * Log(N)). */
int main(){
	string str;
	int n, i, j;

	ios::sync_with_stdio(false);
	
	cin >> n;
	cin >> str;

	// Calculando todos os estados.
	// Não precisamos inicializar explicitamente o caso base pois o caso base é dp[n][j] = 0.
	for (i = n - 1; i >= 0; i--){
		for (j = K - 1; j >= 0; j--){
			if (str[i] == '.'){ // Impossível chegar no final a partir daqui.
				dp[i][j] = INF;
			}
			else if (str[i] == 'p'){ // Pega ou não pega o power-up.
				dp[i][j] = min(dp[i + 1][j], dp[min(n, i + 1 + (1 << (j + 1)))][j + 1]) + 1;
			}
			else{ // Segue para a próxima posição.
				dp[i][j] = dp[i + 1][j] + 1;
			}
		}
	}

	cout << (dp[0][0] >= INF ? -1 : dp[0][0]) << endl;

	return 0;
}