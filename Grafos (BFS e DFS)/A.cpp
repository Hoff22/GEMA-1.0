#include <bits/stdc++.h>

using namespace std;

#define N 100000

vector<int> g[N + 1];
bool seen[N + 1];

/* O(V + E) Percorre o grafo a partir do vértice u, marcando os vértices visitados. */
void dfs(int u){
	int v, i;

	// Marcando o vértice atual u como visitado.
	seen[u] = true;

	// Para cada vértice v adjacente a u.
	for (i = 0; i < (int)g[u].size(); i++){
		v = g[u][i];

		// Se v não foi visitado ainda, chame a DFS para v.
		if (!seen[v]){
			dfs(v);
		}
	}
}

/* O(V + E). */
int main(){
	int n, m, a, b, u, v, i;

	scanf("%d%d%d%d", &n, &m, &a, &b);

	for (i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		g[u].push_back(v); // Adicionando uma aresta direcionada de u para v.
	}

	// Rodando a DFS a partir de a.
	dfs(a);

	// Se b foi visitado a resposta é SIM.
	printf("%s\n", seen[b] ? "SIM" : "NAO");

	return 0;
}