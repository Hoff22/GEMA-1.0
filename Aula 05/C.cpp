#include <bits/stdc++.h>

using namespace std;

/* O(Answer) Retorna o número de maneiras de comer n grãos dado que havia m grãos na última colherada. */
int solve(int n, int m){
	int ans, k;

	// Há apenas 1 maneira de comer 0 grãos.
	if (n == 0){
		return 1;
	}

	// Somamos a resposta para cada múltiplo de m que seja menor ou igual a n.
	for (k = 1, ans = 0; k * m <= n; k++){
		ans += solve(n - k * m, k * m);
	}

	return ans;
}

/* O(Answer). */
int main(){
	int n;

	scanf("%d", &n);

	// A resposta é o número de maneiras de comer n grãos dado que havia 1 grão
	// na última colherada, pois qualquer número é múltiplo de 1.
	printf("%d\n", solve(n, 1));

	return 0;
}