#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int n, m;

	scanf("%d%d", &n, &m);

	// Imprimindo o mesmo que (n | m) - (n & m), pois queremos considerar todos os números exceto aqueles que tem par.
	printf("%d\n", n ^ m);

	return 0;
}