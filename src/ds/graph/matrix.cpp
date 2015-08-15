#include <cstdio>

const int N = 10;
int graph[N][N];

inline void add_edge(int u, int v) {
  graph[u][v] = 1; // weight = 1
  //graph[v][u] = 1; if your graph is undirected
}

inline bool has_edge(int u, int v) {
  return graph[u][v] != 0; // zero weight => no edge
}

int main() {
  // add a bunch of edges
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if ((i + j) == 11) {
        add_edge(i, j);
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (has_edge(i, j)) {
        printf("Nodes %d and %d are adjacent.\n", i, j);
      }
    }
  }

  return 0;
}
