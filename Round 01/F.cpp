#include <bits/stdc++.h>

using namespace std;

#define N 100000

int a[N + 1];
int b[N + 1];
int sum[N + 1]; // Esse vetor é uma soma acumulada mod 10.

/* O(N). */
int main(){
	int ans, n, k, i;

	scanf("%d%d", &n, &k);

	for (i = 1; i <= n; i++){
		scanf("%d", a + i);
	}

	for (i = 1; i <= n; i++){
		scanf("%d", b + i);
	}

	// Para todos os elementos a[i] que são inícios de intervalos de tamanho k.
	for (i = 1, ans = 0; i <= n - k + 1; i++){
		// Propagando as rotações passadas.
		// Somando a rotação acumulada sum[i - 1] e subtraindo a rotação acumulada sum[i - k], pois
		// apenas as rotações iniciadas no intervalo [i - k + 1, i] afetam o valor a[i].
		a[i] = ((a[i] + sum[i - 1] - sum[max(0, i - k)]) % 10 + 10) % 10;

		// Somando na resposta o custo do ajuste do elemento a[i].
		ans += min(abs(b[i] - a[i]), 10 - abs(b[i] - a[i]));

		// Preenchendo a rotação acumulada na posição i.
		sum[i] = ((sum[i - 1] + b[i] - a[i]) % 10 + 10) % 10;
	}

	// Para cada um dos últimos elementos.
	for (; i <= n; i++){
		// Propagando as rotações passadas.
		a[i] = ((a[i] + sum[i - 1] - sum[max(0, i - k)]) % 10 + 10) % 10;

		// Se o elemento a[i] não acabou sendo ajustado corretamente.
		if (a[i] != b[i]){
			break;
		}

		// Preenchendo a rotação acumulada na posição i.
		sum[i] = sum[i - 1];
	}

	// Checando se as rotações produziram uma solução válida.
	if (i <= n){
		printf("-1\n");
	}
	else{
		printf("%d\n", ans);
	}

	return 0;
}