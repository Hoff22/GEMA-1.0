#include <bits/stdc++.h>

using namespace std;

#define N 1000
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

char mat[N][N];
int aux[N][N];
int n, m;

/* O(1) Retorna true se a coordenada (x, y) estiver dentro da matriz NxM. */
bool inside(int x, int y){
	return x >= 0 and x < n and y >= 0 and y < m;
}

/* O(1) Retorna true se a coordenada (x, y) estiver dentro da matriz NxM e se não for uma parede. */
bool valid(int x, int y){
	return inside(x, y) and mat[x][y] != '#';
}

/* O(max(N, M)) Marca todas as posições a partir de (x, y) usando o passo dado pelo vetor direção (x_step, y_step) com a marcação da direção dir. */
void fill(int x, int y, int dir, int x_step, int y_step){
	// Enquanto a casa (x, y) for válida e não tiver sido vista pela mesma direção dir.
	while (valid(x, y) and !(aux[x][y] & (1 << dir))){
		// Marcando a casa (x, y) como vista pela direção dir.
		aux[x][y] |= (1 << dir);

		// Dando um passo para alguma das direções.
		x += x_step;
		y += y_step;
	}
}

/* O(N * M). */
int main(){
	int ans, i, j;

	// Lendo a matriz de caracteres.
	scanf("%d%d%*c", &n, &m);

	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			scanf("%c", mat[i] + j);
		}

		// Ignorando o '\n'.
		scanf("%*c");
	}

	// Podemos ler também da seguinte forma:
	// scanf("%d%d", &n, &m);

	// for (i = 0; i < n; i++){
	// 	for (j = 0; j < m; j++){
	// 		scanf(" %c", mat[i] + j); // Note o espaço antes do %c. Esse espaço faz com que o %c não pegue nenhum whitespace (' ', '\t', '\n').
	// 	}
	// }

	// Para cada elemento da matriz NxM.
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			if (mat[i][j] == 'U'){ // Se for um inimigo olhando pra cima.
				fill(i, j, UP, -1, 0);
			}
			else if (mat[i][j] == 'D'){ // Se for um inimigo olhando pra baixo.
				fill(i, j, DOWN, 1, 0);
			}
			else if (mat[i][j] == 'L'){ // Se for um inimigo olhando pra esquerda.
				fill(i, j, LEFT, 0, -1);
			}
			else if (mat[i][j] == 'R'){ // Se for um inimigo olhando pra direita.
				fill(i, j, RIGHT, 0, 1);
			}
		}
	}

	ans = 0;

	// Contando o número de casas vazias que não são visíveis por nenhum inimigo.
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			// Se aux[i][j] não estiver marcado (for igual a 0) e se a posição mat[i][j] for vazia (não for uma parede).
			if (!aux[i][j] and mat[i][j] == '.'){
				ans++;
			}
		}
	}

	if (ans == 0){
		printf("NO SOLUTION\n");
	}
	else if (ans == 1){
		printf("ONLY ONE SOLUTION\n");
	}
	else{
		printf("MULTIPLE SOLUTIONS\n");
	}

	return 0;
}