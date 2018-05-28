#include <bits/stdc++.h>

using namespace std;

// Esse vetor vai guardar a resposta para qualquer dígito k entre 0 e 9.
int ans[10];

/* O(1). */
int main(){
	int n, k;

	scanf("%d%d", &n, &k);

	// A primeira coisa para se observar nesse problema é que a sequência pode ser simplificada tal que:
	// Fn = 2^(n - 1)
	//
	// Observando o dígito das unidades dos primeiros termos da sequência, podemos ver que há um ciclo:
	// F1 % 10 = 1
	// F2 % 10 = 2 ---
	// F3 % 10 = 4   |
	// F4 % 10 = 8   |
	// F5 % 10 = 6 ---
	// F6 % 10 = 2 ---
	// F7 % 10 = 4   |
	// F8 % 10 = 8   |
	// F9 % 10 = 6 ---
	// ...

	ans[1] = 1; // Sempre aparecerá apenas 1 vez para n >= 1 (em F1).
	ans[2] = ans[4] = ans[6] = ans[8] = (n - 1) / 4; // O número de ciclos COMPLETOS entre 1 e n é igual a (n - 1) / 4.

	// Essas linhas equivalem aos ifs abaixo.
	ans[2] += ((n - 1) % 4 >= 1); // Se o ciclo incompleto já passou por mais um 2.
	ans[4] += ((n - 1) % 4 >= 2); // Se o ciclo incompleto já passou por mais um 2 e 4.
	ans[8] += ((n - 1) % 4 >= 3); // Se o ciclo incompleto já passou por mais um 2, 4 e 8.

	// if ((n - 1) % 4 >= 1){
	// 	ans[2]++;
	// }

	// if ((n - 1) % 4 >= 2){
	// 	ans[4]++;
	// }

	// if ((n - 1) % 4 >= 3){
	// 	ans[8]++;
	// }

	printf("%d\n", ans[k]);

	return 0;
}