#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define INF 0x3f3f3f3f

struct State{
	int u, d;

	State(){}

	State(int u, int d){
		this->u = u;
		this->d = d;
	}

	bool operator < (const State &b) const{
		return d > b.d;
	}
};

int dist[N + 1];
bool in_spt[N + 1];
priority_queue<State> pq;
vector<pair<int, int> > g[N + 1];

/* O(V + E * log(V)). */
void dijkstra(int u){
	int v, w, i;

	// Inicializando.
	memset(in_spt, false, sizeof(in_spt)); // Inicializando os vértices como não pertencentes a Shortest Path Tree.
	memset(dist, 0x3f, sizeof(dist)); // Inicializando a distância inicial como infinito.

	// Inserindo o vértice inicial na fila.
	dist[u] = 0;
	pq.push(State(u, 0));

	// Enquanto ainda houver vértices para adicionar na Shortest Path Tree.
	while (!pq.empty()){
		// Recuperando o próximo vértice a ser processado u.
		u = pq.top().u;
		pq.pop();

		// Se o vértice atual ainda não pertencer a Shortest Path Tree.
		if (!in_spt[u]){
			// O vértice atual agora pertence a Shortest Path Tree. 
			in_spt[u] = true;

			// Para cada vértice v adjacente a u a partir de uma aresta de peso w.
			for (i = 0; i < (int)g[u].size(); i++){
				v = g[u][i].first;
				w = g[u][i].second;

				// Se um caminho melhor foi encontrado para adicionar o vértice v na Shortest Path Tree.
				if (!in_spt[v] and dist[u] + w < dist[v]){
					// Atualize a distância para o vértice v e o insira na fila.
					dist[v] = dist[u] + w;
					pq.push(State(v, dist[v]));
				}
			}
		}
	}
}

/* O(V + E * log(V)). */
int main(){
	int n, m, a, u, v, w, i;

	scanf("%d%d%d", &n, &m, &a);

	for (i = 1; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);

		// Adicionando arestas de u para v e de v para u com peso w.
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	// Rodando o Dijkstra para o vértice inicial a.
	dijkstra(a);

	// Imprimindo as distâncias até o vértice a.
	for (u = 1; u <= n; u++){
		printf("%d\n", dist[u] == INF ? -1 : dist[u]);
	}

	return 0;
}