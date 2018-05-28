#include <bits/stdc++.h>

using namespace std;

#define N 1000
#define M 1000

pair<int, int> e[M + 1];
vector<int> g[N + 1];
bool seen[N + 1];

/* O(V + E) Percorre o grafo a partir do vértice u, marcando os vértices visitados sem passar pela aresta (x, y). */
void dfs(int u, int x, int y){
	int v, i;

	// Marcando o vértice atual u como visitado.
	seen[u] = true;

	// Para cada vértice v adjacente a u.
	for (i = 0; i < (int)g[u].size(); i++){
		v = g[u][i];

		// Se v não foi visitado ainda e a aresta (u, v) for diferente da aresta removida (x, y) chame a DFS para v.
		if (!seen[v] and (min(u, v) != min(x, y) or max(u, v) != max(x, y))){
			dfs(v, x, y);
		}
	}
}

/* O(E * (V + E)). */
int main(){
	int n, m, a, b, u, v, i;

	scanf("%d%d%d%d", &n, &m, &a, &b);

	for (i = 0; i < m; i++){
		scanf("%d%d", &u, &v);

		// Adicionando arestas de u para v e de v para u.
		g[u].push_back(v);
		g[v].push_back(u);
		e[i] = make_pair(u, v); // Salvando a aresta.
	}

	// Para cada aresta.
	for (i = 0; i < m; i++){
		// Rodando uma nova DFS a partir de a para verificar se b é alcançável se retirarmos a aresta e[i].
		memset(seen, false, sizeof(seen));
		dfs(a, e[i].first, e[i].second);

		// Se b não foi visitado a resposta deve ser NAO.
		if (!seen[b]){
			break;
		}
	}

	printf("%s\n", m == 0 or i < m ? "NAO" : "SIM");

	return 0;
}