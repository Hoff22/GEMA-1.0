#include <bits/stdc++.h>

using namespace std;

#define N 13

/* O(Answer) Retorna o número de formas de ganhar o jogo com 3 torres de tamanhos a, b e c. */
int solve(int a, int b, int c){
	// Estado inválido. Não é permitido atirar uma torre de tamanho maior em uma torre de tamanho menor.
	if (a < 0 or b < 0 or c < 0){
		return 0;
	}

	// Se alguma das torres foi destruida, essa é uma solução possível.
	if (a == 0 or b == 0 or c == 0){
		return 1;
	}

	// Atirando das 6 maneiras possíveis.
	return solve(a, b - a, c) + solve(a, b, c - a) + solve(a - b, b, c) + solve(a, b, c - b) + solve(a - c, b, c) + solve(a, b - c, c);
}

/* O(Answer). */
int main(){
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	// Chamando a função recursiva para os tamanhos iniciais a, b e c.
	printf("%d\n", solve(a, b, c));

	return 0;
}