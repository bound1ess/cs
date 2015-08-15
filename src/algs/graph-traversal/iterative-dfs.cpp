#include <cstdio>
#include <stack>

const int N = 10;
bool graph[N][N], marked[N];

inline void dfs(int v) {
  std::stack<int> nodes;
  nodes.push(v);

  while ( ! nodes.empty()) {
    v = nodes.top();
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
