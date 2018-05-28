#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

map<long long, int> freq;

/* O(N * Log(N)). */
int main(){
	map<long long, int>::iterator it;
	vector<long long> aux;
	int n, k, a, i;
	long long ans;

	scanf("%d%d", &n, &k);

	// O(N * Log(N)).
	for (i = 0; i < n; i++){
		scanf("%d", &a);
		freq[a]++;
	}

	ans = 1;

	// O(K * Log(N)) Distribuindo k igualmente entre os primos, pegando primeiro os menores.
	while (k){
		// O(freq.size()) Para cada primo.
		for (it = freq.begin(); it != freq.end() and k; it++){
			// Adicionando o primo atual na resposta.
			ans = (ans * it->first) % MOD;
			it->second--;
			k--;

			// Adicionando o primo atual em um vetor auxiliar para deletá-lo após o for.
			if (it->second == 0){
				aux.push_back(it->first);
			}
		}

		// O(aux.size() * Log(freq.size())) Removendo os primos que agora possuem frequência 0.
		for (i = 0; i < (int)aux.size(); i++){
			freq.erase(aux[i]);
		}

		aux.clear();
	}

	printf("%lld\n", ans);

	return 0;
}