#include <bits/stdc++.h>

using namespace std;

#define N 100000

int v[N];

/* O(N). */
int main(){
	int n, i;

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		scanf("%d", v + i);
	}

	// Imprimindo a diferença entre o maior e o menor elemento.
	printf("%d\n", *max_element(v, v + n) - *min_element(v, v + n));

	return 0;
}