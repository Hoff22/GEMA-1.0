#include <bits/stdc++.h>

using namespace std;

#define N 5000

int dp[N + 1];
int a[N + 1];

/* O(N^2). */
int main(){
	int n, i, j;

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		scanf("%d", a + i);
	}

	// Calculando a Longest Increasing Subsequence terminando na posição i.
	for (i = 0; i < n; i++){
		// Incializando a Longest Increasing Subsequence terminando em i com 1 (LIS com apenas o elemento a[i]).
		dp[i] = 1;

		// Para toda posição j anterior a i.
		for (j = 0; j < i; j++){
			if (a[j] <= a[i]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	
	// A resposta será N - Longest Increasing Subsequence, pois devemos manter a Longest Increasing Subsequence
	// e apenas alterar os valores que não pertencem a Longest Increasing Subsequence.
	printf("%d\n", n - *max_element(dp, dp + n));

	return 0;
}