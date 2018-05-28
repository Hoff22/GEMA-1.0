#include <bits/stdc++.h>

using namespace std;

#define N 1000

int dp[N + 1][N + 1];

/* O(|A| * |B|). */
int main(){
	string a, b;
	int i, j;

	ios::sync_with_stdio(false);

	cin >> a >> b;

	// Programação dinâmica iterativa.
	// Os casos base dp[a.size()][j] e dp[i][b.size()] já estão preenchidos pois dp é inicialmente 0.
	for (i = a.size() - 1; i >= 0; i--){
		for (j = b.size() - 1; j >= 0; j--){
			if (a[i] == b[j]){ // Se os caracteres forem iguais, devemos dar match.
				dp[i][j] = 1 + dp[i + 1][j + 1];
			}
			else{ // Se os caracteres forem diferentes, devemos escolher entre consumir a[i] ou b[j].
				dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}

	cout << dp[0][0] << endl;;

	return 0;
}