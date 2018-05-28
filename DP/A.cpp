#include <bits/stdc++.h>

using namespace std;

#define N 100000

int a[N + 1];
int n;

/* O(N). */
int main(){
	int ans, i;

	scanf("%d", &n);

	for (i = 1; i < n; i++){
		scanf("%d", a + i);
	}

	// Guardando em a[i] a posição máxima alcançável a partir de i.
	for (i = 1; i <= n; i++){
		a[i] = min(n, i + a[i]);
	}

	// Guardando em a[i] a posição máxima alcançável a partir de alguma posição <= i.
	for (i = 2; i <= n; i++){
		a[i] = max(a[i - 1], a[i]);
	}

	// Pulando de posição em posição enquanto ainda não chegou em n.
	for (i = 1, ans = 0; i < n; ans++){
		i = a[i];
	}

	printf("%d\n", ans);

	return 0;
}