#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int x, y, p;

	scanf("%d", &p);

	// Resolvendo x^2 - y^2 = p temos:
	// (x + y) * (x - y) = p
	// 
	// Como p só tem 1 e p como divisores e pedimos que x e y sejam naturais
	// (ou seja, não negativos), temos o sistema:
	// x + y = p
	// x - y = 1

	if (p == 2){
		// A fórmula só funciona se p for ímpar, pois se p for par então x e y não dão inteiros.
		printf("0\n"); // Nenhuma solução.
	}
	else{
		// Resolvendo o sistema:
		x = (p + 1) / 2;
		y = (p - 1) / 2;
		
		printf("1\n"); // Apenas 1 solução.
		printf("%d %d\n", x, y);
	}

	return 0;
}