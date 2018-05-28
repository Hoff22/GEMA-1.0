#include <bits/stdc++.h>

using namespace std;

#define N 20

int v[N];

/* O(N * 2^N). */
int main(){
	int ans, sum, n, x, i, j;

	scanf("%d%d", &n, &x);

	for (i = 0; i < n; i++){
		scanf("%d", v + i);
	}

	// Existem 2^N subsets, então testamos cada um deles.
	for (i = 0, ans = 0; i < (1 << n); i++){
		sum = 0;

		// Para cada um dos N elementos.
		for (j = 0; j < n; j++){
			// Se o j-ésimo bit estiver setado, então pegamos o elemento v[j].
			if ((1 << j) & i){
				sum += v[j];
			}
		}

		// Se a soma desse subset for x.
		if (sum == x){
			ans++;
		}
	}

	printf("%d\n", ans);

	return 0;
}