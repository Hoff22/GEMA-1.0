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
	int ans, n, m, u, v, i;

	scanf("%d%d", &n, &m);

	for (i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);

		// Adicionando arestas de u para v e de v para u.
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// Contando o número de componentes conexas.
	for (u = 1, ans = 0; u <= n; u++){
		// Se o vértice u não foi visitado, rode uma DFS a partir dele e some 1 a resposta.
		if (!seen[u]){
			ans++;
			dfs(u);
		}
	}

	printf("%d\n", ans);

	return 0;
}