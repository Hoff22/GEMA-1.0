#include <bits/stdc++.h>

using namespace std;

#define N 1000

char mat[N][N];
bool seen[N][N];
int n, m;

/* O(1) Retorna true se a casa (x, y) estiver dentro da matriz NxM. */
bool inside(int x, int y){
	return x >= 0 and x < n and y >= 0 and y < m;
}

/* O(N * M). */
int main(){
	int x, y, i, j;

	scanf("%d%d%*c", &n, &m);

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%c", mat[i] + j);
		}
	
		scanf("%*c");
	}

	scanf("%d%d", &x, &y);

	// Enquanto o robô estiver dentro da matriz e a casa (x, y) não tiver sido visitada ainda.
	while (inside(x, y) and !seen[x][y]){
		// Marcando a casa (x, y) como já visitada.
		seen[x][y] = true;
		
		if (mat[x][y] == 'U'){ // Para cima.
			x--;
		}
		else if (mat[x][y] == 'D'){ // Para baixo.
			x++;
		}
		else if (mat[x][y] == 'L'){ // Para esquerda.
			y--;
		}
		else{ // Para direita.
			y++;
		}
	}

	// Se saiu do while acima mas o robô continua dentro da matriz, então ele chegou
	// em alguma casa (x, y) que já havia sido visitada antes. Loop infinito.
	if (inside(x, y)){
		printf("EOQ\n");
	}
	else{
		printf("AE MLK\n");
	}

	return 0;
}