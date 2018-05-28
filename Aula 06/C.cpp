#include <bits/stdc++.h>

using namespace std;

#define N 100000

int v[N];

/* O(M * Log(N)). */
int main(){
	int n, m, x, l, r, i;

	scanf("%d%d", &n, &m);

	for (i = 0; i < n; i++){
		scanf("%d", v + i);
	}

	// Para cada query.
	while (m--){
		scanf("%d", &x);

		// Obtendo os índices dos dois candidatos.
		r = upper_bound(v, v + n, x) - v; // Busca binária pelo primeiro elemento maior que x.
		l = r - 1; // Um anterior ao primeiro elemento maior que x.

		if (l >= 0 and r < n){ // Se ambos forem índices válidos.
			// Checando qual dos dois candidatos é mais próximo de x.
			if (x - v[l] <= v[r] - x){
				printf("%d\n", v[l]);
			}
			else{
				printf("%d\n", v[r]);
			}
		}
		else if (l >= 0){ // Se apenas l for índice válido.
			printf("%d\n", v[l]);
		}
		else if (r < n){ // Se apenas r for índice válido.
			printf("%d\n", v[r]);
		}
	}

	return 0;
}