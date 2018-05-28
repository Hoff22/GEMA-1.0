#include <bits/stdc++.h>

using namespace std;

/* O(Log(N)). */
int main(){
	long long n;

	scanf("%lld", &n);

	// Removendo os fatores 2 do número n.
	while (n % 2 == 0){
		n /= 2;
	}

	printf("%lld\n", n);

	return 0;
}