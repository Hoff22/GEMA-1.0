#include <bits/stdc++.h>

using namespace std;

/* O(N * M). */
int main(){
	int n, m, x, i, j;

	scanf("%d%d", &n, &m);

	// Para cada elemento da matriz NxM.
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%d", &x);

			if (!x){ // O mesmo que if (x == 0)
				printf("%d %d\n", i, j);
			}
		}
	}

	return 0;
}