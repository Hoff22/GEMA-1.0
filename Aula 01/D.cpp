#include <bits/stdc++.h>

using namespace std;

/* O(1). */
int main(){
	int a, b, c;

	scanf("%d%d%d", &a, &b, &c);

	// Testando todas as 6 (3!) permutações de a, b e c.
	if (a > b and b > c){
		printf("%d\n%d\n%d\n", a, b, c);
	}
	else if (a > c and c > b){
		printf("%d\n%d\n%d\n", a, c, b);
	}
	else if (b > a and a > c){
		printf("%d\n%d\n%d\n", b, a, c);
	}
	else if (b > c and c > a){
		printf("%d\n%d\n%d\n", b, c, a);
	}
	else if (c > a and a > b){
		printf("%d\n%d\n%d\n", c, a, b);
	}
	else{
		printf("%d\n%d\n%d\n", c, b, a);
	}

	return 0;
}