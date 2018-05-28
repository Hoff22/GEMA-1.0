#include <bits/stdc++.h>

using namespace std;

#define M 1000

int freq[M + 1];

/* O(N + M). */
int main(){
	string str;
	int n, i, j;

	cin >> n;

	// Para cada dia.
	for (i = 0; i < n; i++){
		cin >> str;
		freq[(int)str.size()]++; // Incrementamos em 1 a frequência (número de ocorrências) do tamanho str.size().
	}

	// i itera sobre todas as frequências e j guarda o índice que possui a maior frequência.
	for (i = 2, j = 1; i <= M; i++){
		if (freq[i] > freq[j]){
			j = i;
		}
	}

	// Imprimindo o índice de maior frequência (moda).
	cout << j << endl;

	return 0;
}