#include <bits/stdc++.h>

using namespace std;

#define N 100000

long long x[N + 1];
long long y[N + 1];
long long d[N + 1];

/* O(N). */
int main(){
	long long r;
	int n, i;
	
	scanf("%lld%d", &r, &n);

	for (i = 1; i <= n; i++){
		scanf("%lld%lld", x + i, y + i);
	}

	// Calculando as distâncias ao quadrado até a origem.
	for (i = 1; i <= n; i++){
		d[i] = x[i] * x[i] + y[i] * y[i];
	}

	// Imprimindo o raio menos a maior das distâncias até a origem.
	printf("%lf\n", r - sqrt(*max_element(d + 1, d + 1 + n)));

	return 0;
}