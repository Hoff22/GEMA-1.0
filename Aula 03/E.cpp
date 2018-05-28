#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	long long n, b;

	scanf("%lld%lld", &n, &b);

	// A resposta é uma soma de PA com o primeiro elemento dado por B, o último elemento dado por B - N + 1 e o número de elementos dado por N. 
	printf("%lld\n", ((2 * b - n + 1) * n) / 2);

	return 0;
}