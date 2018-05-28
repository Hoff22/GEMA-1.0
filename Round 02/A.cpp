#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int r, g, b;

	scanf("%d%d%d", &r, &g, &b);

	// Imprimindo a soma de cada cor dividida por 2 truncada.
	printf("%d\n", (r / 2) + (g / 2) + (b / 2));

	return 0;
}