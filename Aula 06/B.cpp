#include <bits/stdc++.h>

using namespace std;

/* O(Log(R - L + 1)). */
int main(){
	int op, l, r, m;

	// A resposta pode ser qualquer número no intervalo [1, 10].
	l = 1;
	r = 10;

	// Enquanto não tiver adivinhado o número correto.
	do{
		// Encontrando o meio do intervalo.
		m = (l + r) / 2;

		// Chutando o meio.
		printf("%d\n", m);
		fflush(stdout);

		// Recebendo a resposta do judge.
		scanf("%d", &op);
			
		if (op == 0){
			// Se o número for menor que m, devemos buscar agora no intervalo [l, m - 1].
			r = m - 1;
		}
		else if (op == 1){
			// Se o número for maior que m, devemos buscar agora no intervalo [m + 1, r].
			l = m + 1;
		}
	}while (op != 2);

	return 0;
}