#include <bits/stdc++.h>

using namespace std;

#define N 10

map<string, int> freq;
int f[N + 1];

/* O(N * |S| * Log(N)). */
int main(){
	map<string, int>::iterator it;
	int ans, n, i;
	string str;

	ios::sync_with_stdio(false);

	// Pré-calculando fatoriais até N!.
	f[0] = 1;

	for (i = 1; i <= N; i++){
		f[i] = f[i - 1] * i;
	}

	cin >> n;

	for (i = 1; i <= n; i++){
		cin >> str;
		freq[str]++;
	}

	ans = f[n];

	// A resposta é uma permutação com repetição (Multinomial Coefficient), então basta
	// dividirmos N! pelo fatorial de cada frequência freq[s] para cada string s.
	for (it = freq.begin(); it != freq.end(); it++){
		ans /= f[it->second];
	}

	printf("%d\n", ans);

	return 0;
}