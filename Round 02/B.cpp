#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int n;

	scanf("%d", &n);

	printf("%d\n", __builtin_popcount(n));

	return 0;
}