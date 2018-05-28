#include <bits/stdc++.h>

using namespace std;

bool seen[61];

/* O(N), tal que N é a quantidade de valores na cartela. */
int main(){
	int x, i;
	bool ans;
	char c;

	for (i = 1; i <= 60; i++){
		scanf(" %c", &c);

		// Marcando a posição i.
		if (c == 'x'){
			seen[i] = true;
		}
	}

	// Inicializando.
	ans = true;

	// Para cada número sorteado.
	for (i = 1; i <= 6; i++){
		scanf("%d", &x);

		// Checando se todos os números sorteados estão marcados.
		ans = ans and seen[x];
	}

	if (ans){
		printf("S\n");
	}
	else{
		printf("N\n");
	}

	return 0;
}