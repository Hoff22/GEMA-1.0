#include <bits/stdc++.h>

using namespace std;

#define N 1000

int dp[N + 1][N + 1];
string a, b;

/* O(|A| * |B|). */
int solve(int x, int y){
	// Se alguma das strings acabou a resposta é 0.
	if (x == (int)a.size() or y == (int)b.size()){
		return 0;
	}

	// Se esse estado já foi calculado, retorne seu valor.
	if (dp[x][y] != -1){
		return dp[x][y];
	}

	// Se os caracteres forem iguais some 1.
	if (a[x] == b[y]){
		return dp[x][y] = solve(x + 1, y + 1) + 1;
	}

	// Se os caracteres forem diferentes consuma um dos dois.
	return dp[x][y] = max(solve(x + 1, y), solve(x, y + 1));
}

/* O(|A| * |B|). */
int main(){
	ios::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));

	cin >> a >> b;

	cout << solve(0, 0) << endl;;

	return 0;
}