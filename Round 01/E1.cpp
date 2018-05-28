#include <bits/stdc++.h>

using namespace std;

/* O(K). */
int main(){
	long long num, den, n, k, i;
	
	scanf("%lld%lld", &n, &k);

	num = den = 1;

	// Calculando N! / (N - K)!.
	for (i = n; i > n - k; i--){
		num *= i;
	}

	// Calculando K!.
	for (i = 2; i <= k; i++){
		den *= i;
	}

	// Calculando N! / (K! * (N - K)!).
	printf("%lld\n", num / den);

	return 0;
}