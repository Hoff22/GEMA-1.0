#include <bits/stdc++.h>

using namespace std;

/* O(N). */
int main(){
	int ans, n, i, j;
	string str;

	cin >> n;
	cin >> str;

	// Nesse problema vamos contar o número de pares de caracteres que eram para ser iguais, mas são diferentes.
	ans = 0;

	// i indexa a string da esquerda para a direita e j indexa a string da direita para a esquerda.
	// Rodamos enquanto i < j e isso já resolve para strings de tamanho par e strings de tamanho ímpar.
	for (i = 0, j = n - 1; i < j; i++, j--){
		// O par (str[i], str[j]) era para ser igual, se for diferente incrementamos a resposta em 1.
		if (str[i] != str[j]){
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}