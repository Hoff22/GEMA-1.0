#include <bits/stdc++.h>

using namespace std;

#define M 1000

int freq[M + 1];

/* O(N + M). */
int main(){
	string str;
	int n, i;

	cin >> n;

	// Para cada dia.
	for (i = 0; i < n; i++){
		cin >> str;
		freq[(int)str.size()]++; // Incrementamos em 1 a frequência (número de ocorrências) do tamanho str.size().
	}

	// Imprimindo o índice de maior frequência (moda).
	cout << max_element(freq + 1, freq + M + 1) - freq << endl;

	return 0;
}