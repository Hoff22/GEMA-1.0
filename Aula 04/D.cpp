#include <bits/stdc++.h>

using namespace std;

/* O(1) Retorna a soma de uma PG com o primeiro elemento dado por a1, a razão (quociente)
dado por q e o número de elementos dado por n. */
double pg(double a1, double q, int n){
	return (a1 * (pow(q, n) - 1.0)) / (q - 1.0);
}

/* O(1). */
int main(){
	double p;
	int n;

	scanf("%d%lf", &n, &p);

	// A resposta é igual a soma de uma PG de razão (p - p^2) multiplicado por p.
	printf("%.4lf\n", p * pg(1.0, p - p * p, (n - 1) / 2 + 1));

	return 0;
}