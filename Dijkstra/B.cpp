#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define N 100000
#define M 100000
#define FROM_A 0
#define FROM_B 1

struct Edge{
	int u, v, w;

	Edge(){}

	Edge(int u, int v, int w){
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

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

Edge e[M + 1];
int dist[2][N + 1];
bool in_spt[N + 1];
priority_queue<State> pq;
vector<pair<int, int> > g[N + 1];

/* O(V + E * log(V)). */
void dijkstra(int from, int u){
	int v, w, i;

	// Inicializando.
	memset(in_spt, false, sizeof(in_spt)); // Inicializando os vértices como não pertencentes a Shortest Path Tree.

	// Inserindo o vértice inicial na fila.
	dist[from][u] = 0;
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
				if (!in_spt[v] and dist[from][u] + w < dist[from][v]){
					// Atualize a distância para o vértice v e o insira na fila.
					dist[from][v] = dist[from][u] + w;
					pq.push(State(v, dist[from][v]));
				}
			}
		}
	}
}

/* O(V + E * log(V)). */
int main(){
	int n, m, a, b, u, v, w, i;

	scanf("%d%d%d%d", &n, &m, &a, &b);

	for (i = 1; i <= m; i++){
		scanf("%d%d%d", &u, &v, &w);

		// Adicionando arestas de u para v e de v para u com peso w.
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
		e[i] = Edge(u, v, w); // Salvando a aresta.
	}

	memset(dist, 0x3f, sizeof(dist)); // Inicializando a distância inicial como infinito.
	dijkstra(FROM_A, a); // Rodando o Dijkstra a partir de A.
	dijkstra(FROM_B, b); // Rodando o Dijkstra a partir de B.

	// Para cada aresta.
	for (i = 1; i <= m; i++){
		// Aresta (u, v) de peso w.
		u = e[i].u;
		v = e[i].v;
		w = e[i].w;

		// Se a distância de A até B for a mesma que de A até u, de u até v (w) e de v até B. 
		// Ou se a distância de A até B for a mes a que de A até v, de v até u (w) e de u até B.
		if (dist[FROM_A][u] + w + dist[FROM_B][v] == dist[FROM_A][b] or dist[FROM_A][v] + w + dist[FROM_B][u] == dist[FROM_A][b]){
			printf("sim\n");
		}
		else{
			printf("nao\n");
		}
	}

	return 0;
}