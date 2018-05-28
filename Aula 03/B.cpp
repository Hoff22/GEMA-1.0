#include <bits/stdc++.h>

using namespace std;

#define N 100000

int v[N];

/* O(N). */
int main(){
	int n, ans, i;

	// Ignoramos o segundo inteiro H, pois é irrelevante para o nosso problema.
	scanf("%d%*d", &n);

	for (i = 0; i < n; i++){
		scanf("%d", v + i);
	}

	ans = 0;

	// Somando as as diferenças absolutas entre o andares.
	for (i = 1; i < n; i++){
		ans += abs(v[i] - v[i - 1]);
	}

	// Multiplicando a resposta por 4 pois a distância entre andares consecutivos é 4.
	printf("%d\n", 4 * ans);

	return 0;
}