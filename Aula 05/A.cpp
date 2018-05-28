#include <bits/stdc++.h>

using namespace std;

#define N 1000000

char str[N + 2];
char ans[N + 2];

/* O(1) Retorna true se o caractere passado for uma vogal. */
bool vowel(char c){
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

/* O(N). */
int main(){
	int i, j;

	scanf("%[^\n]", str);

	// A primeira letra sempre é igual.
	ans[0] = str[0];

	// i indexa a letra atual da string original.
	// j indexa a última letra colocada na string resposta.
	for (i = 1, j = 0; str[i]; i++){
		// Apenas coloca a letra atual na string resposta se a letra atual for consoante
		// ou se a última letra colocada na string resposta for consoante.
		if (!vowel(str[i]) or !vowel(ans[j])){
			j++;
			ans[j] = str[i];
		}
	}

	printf("%s\n", ans);

	return 0;
}