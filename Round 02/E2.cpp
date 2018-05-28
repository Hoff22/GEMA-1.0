#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define MAX 100000000

int p[N + 1];

/* O(K * Log(N)) Retorna true se for possível chegar até a última pedra com no máximo K pulos de tamanho máximo X. */
bool check(int n, int x, int k){
	int i;

	// Realizando pulos de no máximo X enquanto houver pulos restantes.
	for (i = 0; i < n - 1 and k; k--){
		i = upper_bound(p, p + n, p[i] + x) - p - 1;
	}

	return i >= n - 1;
}

/* O(K * Log(N) * Log(MAX)). */
int main(){
	int n, k, l, r, m, i;

	scanf("%d%d", &n, &k);

	for (i = 0; i < n; i++){
		scanf("%d", p + i);
	}

	l = 0;
	r = MAX + 1;

	// Busca binária na resposta. Queremos encontrar o primeiro valor X tal qual check() retorne true.
	while (l < r){
		m = (l + r) / 2;

		// Se for possível chegar na última pedra com pulos de tamanho máximo M,
		// então com qualquer pulo maior que M também será possível.
		if (check(n, m, k)){ // Devemos buscar no intervalo [l, m] se for possível com pulos de tamanho máximo M.
			r = m;
		}
		else{ // devemos buscar no intervalo [m + 1, r] se não for possível com pulos de tamanho máximo M.
			l = m + 1;
		}
	}

	// Após o while l e r serão iguais.
	printf("%d\n", l);

	return 0;
}