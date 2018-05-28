#include <bits/stdc++.h>

using namespace std;

#define N 1000000

long long x[N + 1];
long long sum[N + 1];

/* O(N + M). */
int main(){
	int n, m, l, r, i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++){
		scanf("%lld", x + i);
	}

	// O(N) Calculando a soma acumulada de todos os x[i].
	for (i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + x[i];
	}

	scanf("%d", &m);

	// O(M) Para cada query (consulta).
	while (m--){
		scanf("%d%d", &l, &r);

		// O(1) Imprimindo a soma no intervalo [l, r].
		printf("%lld\n", sum[r] - sum[l - 1]);
	}

	return 0;
}