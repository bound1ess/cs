#include <cstdio>
#include <queue>

const int N = 10;
bool graph[N][N], marked[N];

inline void bfs(int v) {
  std::queue<int> nodes;
  nodes.push(v);

  while ( ! nodes.empty()) {
    v = nodes.front();
    nodes.pop();

    if ( ! marked[v]) {
      marked[v] = true;
      printf("Found %d\n", v);

      for (int i = 0; i < N; ++i) {
        if (graph[v][i]) {
          nodes.push(i);
        }
      }
    }
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      graph[i][j] = true;
    }
  }

  for (int i = 0; i < N; ++i) {
    bfs(i);
  }

  return 0;
}
