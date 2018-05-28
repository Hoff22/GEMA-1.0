#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int n, m;

	scanf("%d%d", &n, &m);

	// Se o número de blocos não for múltiplo de (m + 1), Loppa sempre pode tirar n % (m + 1) blocos
	// de forma a obter um número de blocos múltiplo de (m + 1).
	if (n % (m + 1)){
		printf("O Loppa vai mandar bem\n");
	}
	else{
		printf("O Loppa vai ficar pistola\n");
	}
	
	printf("%d\n", n % (m + 1));

	return 0;
}