#include <cstdio>

const int N = 10;
bool graph[N][N], marked[N];

void dfs(int v) {
  if ( ! marked[v]) {
    marked[v] = true;
    printf("Found node %d\n", v);

    for (int i = 0; i < N; ++i) {
      if (graph[v][i]) {
        dfs(i);
      }
    }
  }
}

int main() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i + j == 11) {
        graph[i][j] = true;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    dfs(i);
  }

  return 0;
}
