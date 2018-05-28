#include <bits/stdc++.h>

using namespace std;

/* O(N). */
int main(){
	int n, ans, na, cur, i, j;
	string str;

	cin >> str;
	n = str.size();

	na = 0;

	// Calculando o número total de 'a's na string.
	for (i = 0; i < n; i++){
		if (str[i] == 'a'){
			na++;
		}
	}

	ans = 0;
	cur = 0;

	// Para cada posição que houver um 'b'.
	// cur irá guardar o número de 'a's a esquerda.
	// (na - cur) equivale ao número de 'a's a direita.
	for (i = 0; i < n; i++){
		if (str[i] == 'a'){
			cur++; // Atualizando o número de 'a's a esquerda.
		}
		else{
			// Ao chegar em um 'b' nós já temos o número de 'a's a esquerda e o número de 'a's
			// a direita calculados. Basta somar cur * (na - cur) na resposta.
			ans += cur * (na - cur);
		}
	}

	cout << ans << endl;

	return 0;
}