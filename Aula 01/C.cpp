#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int n, m;

	scanf("%d%d", &n, &m);

	// Imprimindo o número de casas dividido por dois (arredondado pra cima).
	printf("%d\n", (n * m + 1) / 2);

	return 0;
}