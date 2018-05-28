#include <bits/stdc++.h>

using namespace std;

/* O(N). */
int main(){
	int ans, n, x, i;

	scanf("%d", &n);

	// Nesse problema precisamos contar o número de cartas pares.
	ans = 0;

	for (i = 0; i < n; i++){
		scanf("%d", &x);

		// Essa linha é equivalente ao if abaixo, pois expressões booleanas como (x % 2 == 0)
		// retornam 0 se a expressão for falsa e 1 se a expressão for verdadeira. 
		ans += (x % 2 == 0);

		// if (x % 2 == 0){
		// 	ans++;
		// }
	}

	printf("%d\n", ans);

	return 0;
}