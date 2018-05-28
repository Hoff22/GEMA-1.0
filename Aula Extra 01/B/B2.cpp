#include <bits/stdc++.h>

using namespace std;

#define N 100000

long long v[N + 1];

/* O(N). */
int main(){
	int n, k, i, j;
	long long sum;

	scanf("%d%d", &n, &k);

	for (i = 1; i <= n; i++){
		scanf("%lld", v + i);
	}

	sum = 0;

	// Calculando a soma do primeiro intervalo [1, k].
	for (i = 1; i <= k; i++){
		sum += v[i];
	}

	printf("%lf\n", sum / (double)k);

	// Para cada um dos outros intervalos.
	for (i = 2; i <= n - (k - 1); i++){
		// Precisamos calcular a soma do intervalo [i, i + k - 1] a partir da soma que
		// já possuímos do intervalo [i - 1, i + k - 2].
		// Para isso basta subtrairmos o primeiro elemento do intervalo anterior e
		// somar o último elemento do novo intervalo.
		sum -= v[i - 1];
		sum += v[i + k - 1];

		printf("%lf\n", sum / (double)k);
	}

	return 0;
}