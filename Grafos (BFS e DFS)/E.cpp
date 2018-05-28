#include <bits/stdc++.h>

using namespace std;

#define N 1000

vector<int> g[N + 1];
int mat[N + 1][N + 1];
int dist[N + 1][N + 1];

/* O(V + E). Calcula o vetor de distâncias dist[x] em relação ao vértice inicial x. */
void bfs(int x){
	queue<int> q;
	int u, v, i;

	// Colocando o vértice inicial na fila.
	dist[x][x] = 0;
	q.push(x);

	// Enquanto a fila não estiver vazia.
	while (!q.empty()){
		// Recuperando o próximo vértice a ser processado.
		u = q.front();
		q.pop();

		// Para cada vértice v adjacente a u.
		for (i = 0; i < (int)g[u].size(); i++){
			v = g[u][i];

			// Se a distância até v ainda não foi calculada.
			if (dist[x][v] == -1){
				// Atualize a distância de v e o insira atrás da fila.
				dist[x][v] = dist[x][u] + 1;
				q.push(v);
			}
		}
	}
}

/* O(V * (V + E)). */
int main(){
	int n, u, v;
	bool ans;

	scanf("%d", &n);

	for (u = 1; u <= n; u++){
		for (v = 1; v <= n; v++){
			scanf("%d", mat[u] + v);
		}
	}

	// Construindo o grafo explicitamente, adicionando arestas (u, v) se a distância entre u e v for 1.
	for (u = 1; u <= n; u++){
		for (v = 1; v <= n; v++){
			if (mat[u][v] == 1){
				g[u].push_back(v);
			}
		}
	}

	// Inicializando a matriz de distâncias.
	memset(dist, -1, sizeof(dist));

	// Rodando uma BFS a partir de cada vértice para preencher toda a matriz de distâncias.
	for (u = 1; u <= n; u++){
		bfs(u);
	}

	// Agora basta checar se as matrizes são idênticas. Se alguma distância diferir, ans será false.
	for (u = 1, ans = true; u <= n; u++){
		for (v = 1; v <= n; v++){
			ans = ans and dist[u][v] == mat[u][v];
		}
	}

	printf("%s\n", ans ? "sim" : "nao");

	return 0;
}