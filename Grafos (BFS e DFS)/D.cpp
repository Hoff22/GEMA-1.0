#include <bits/stdc++.h>

using namespace std;

#define N 100000

vector<int> g[N + 1];
int dist[N + 1];

/* O(V + E). Calcula o vetor de distâncias dist em relação ao vértice inicial u. */
void bfs(int u){
	queue<int> q;
	int v, i;

	// Incializando as distâncias com um valor inválido -1.
	memset(dist, -1, sizeof(dist));

	// Colocando o vértice inicial na fila.
	dist[u] = 0;
	q.push(u);

	// Enquanto a fila não estiver vazia.
	while (!q.empty()){
		// Recuperando o próximo vértice a ser processado.
		u = q.front();
		q.pop();

		// Para cada vértice v adjacente a u.
		for (i = 0; i < (int)g[u].size(); i++){
			v = g[u][i];

			// Se a distância até v ainda não foi calculada.
			if (dist[v] == -1){
				// Atualize a distância de v e o insira atrás da fila.
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
}

/* O(V + E). */
int main(){
	int n, m, a, b, u, v, i;

	scanf("%d%d%d%d", &n, &m, &a, &b);

	for (i = 1; i <= m; i++){
		scanf("%d%d", &u, &v);

		// Adicionando arestas de u para v e de v para u.
		g[u].push_back(v);
		g[v].push_back(u);
	}

	// Rodando uma BFS a partir de a.
	bfs(a);

	// Imprimindo a distância de a até b.
	printf("%d\n", dist[b]);

	return 0;
}