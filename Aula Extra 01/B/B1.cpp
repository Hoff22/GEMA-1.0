#include <bits/stdc++.h>

using namespace std;

#define N 100000

long long v[N + 1];

/* O(N^2). */
int main(){
	int n, k, i, j;
	long long sum;

	scanf("%d%d", &n, &k);

	for (i = 1; i <= n; i++){
		scanf("%lld", v + i);
	}

	// Para cada possível início de um segmento de tamanho K.
	for (i = 1; i <= n - (k - 1); i++){
		sum = 0;
			
		// Somamos os K elementos a partir de i.
		for (j = i; j < i + k; j++){
			sum += v[j];
		}

		printf("%lf\n", sum / (double)k);
	}

	return 0;
}