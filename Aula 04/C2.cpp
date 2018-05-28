#include <bits/stdc++.h>

using namespace std;

#define N 1000000

long long x[N + 1];
long long sum[N + 1];
int n;

/* O(1) Retorna a soma das coordenadas no intervalo [l, r].
Ou seja, retorna x[l] + x[l + 1] + ... + x[r - 1] + x[r]. */
long long query(int l, int r){
	return sum[r] - sum[l - 1];
}

/* O(1) Retorna a soma das distâncias de x[k] para todas as outras coordenadas x[i]. */
long long cost(int k){
	return (2 * k - n - 1) * x[k] + query(k + 1, n) - query(1, k - 1);
}

/* O(N). */
int main(){
	int i, j;

	scanf("%d", &n);

	// O(N).
	for (i = 1; i <= n; i++){
		scanf("%lld", x + i);
	}

	// O(N) Calculando a soma acumulada de todos os x[i].
	for (i = 1; i <= n; i++){
		sum[i] = sum[i - 1] + x[i];
	}

	// O(N) Buscando a coordenada x[j] que possui custo mínimo.
	for (i = 2, j = 1; i <= n; i++){
		if (cost(i) < cost(j)){
			j = i;
		}
	}

	// O(1) Imprimindo a coordenada x[j] de custo mínimo.
	printf("%lld\n", x[j]);

	return 0;
}