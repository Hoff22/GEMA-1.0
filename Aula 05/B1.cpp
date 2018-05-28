#include <bits/stdc++.h>

using namespace std;

#define N 20

int v[N + 1];
int x;

/* O(2^N) Retorna o número de maneiras de somar x com os n primeiros elementos, dado que a soma atual é sum. */
int solve(int n, int sum){
	// Se não houver mais elementos para olhar, basta checarmos se a soma obtida é x.
	if (n == 0){
		return sum == x;
	}

	// Podemos escolher pegar ou não pegar o n-ésimo elemento.
	return solve(n - 1, sum + v[n]) + solve(n - 1, sum);
}

/* O(2^N). */
int main(){
	int n, i, j;

	scanf("%d%d", &n, &x);

	for (i = 1; i <= n; i++){
		scanf("%d", v + i);
	}

	// A resposta é o número de maneiras de somar x considerando todos os elementos, dado que a soma inicial é 0.
	printf("%d\n", solve(n, 0));

	return 0;
}