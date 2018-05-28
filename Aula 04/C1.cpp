#include <bits/stdc++.h>

using namespace std;

#define N 1000000

int x[N + 1];

/* O(N). */
int main(){
	int n, i;

	scanf("%d", &n);

	// O(N).
	for (i = 1; i <= n; i++){
		scanf("%d", x + i);
	}

	// O(1) Imprimindo a mediana.
	printf("%d\n", x[(n + 1) / 2]);

	return 0;
}