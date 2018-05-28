#include <bits/stdc++.h>

using namespace std;

/* O(T). */
int main(){
	int a, b, t;

	scanf("%d%d", &a, &b);

	// Inicializando o tempo decorrido com 0.
	t = 0;

	// Enquanto a não for estritamente maior que b.
	// while (!(a > b)) é o mesmo que while (a <= b)
	while (a <= b){
		a *= 3; // O mesmo que a = 3 * a.
		b *= 2; // O mesmo que b = b * b.
		t++; // Incrementando o tempo decorrido.
	}

	// Imprimindo o tempo decorrido.
	printf("%d\n", t);

	return 0;
}