#include <bits/stdc++.h>

using namespace std;

#define N 1000

int mat[N][N];

/* O(N * M). */
int main(){
	int n, m, i, j;
	bool ans;

	scanf("%d%d", &n, &m);

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%d", mat[i] + j);
		}
	}
	
	// Para cada coluna j.
	for (j = 0, ans = true; j < m; j++){
		// Para cada um dos elementos da coluna j.
		for (i = 0; i < n; i++){
			// Se mat[i][j] for 0, quebramos a execução do for.
			if (!mat[i][j]){
				break;
			}
		}

		// A resposta é sim se já for sim antes e houver um 0 na coluna j atual.
		// i < n é verdadeiro se o break ocorreu, ou seja, se encontrou um 0.
		ans = ans and i < n;
	}

	if (ans){
		printf("S\n");
	}
	else{
		printf("N\n");
	}

	return 0;
}