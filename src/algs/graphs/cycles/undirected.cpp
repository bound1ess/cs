#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > adj;
vector<bool> visited;

bool check(int v, int parent = -1) {
  visited[v] = true;

  for (int i: adj[v]) {
    if ( ! visited[i]) {
      if (check(i, v)) {
        return true;
      }
    } else if (i != parent) {
      return true;
    }
  }

  return false;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  adj.resize(n), visited.resize(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    adj[u].push_back(v), adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if ( ! visited[i] && check(i)) {
      printf("There is a cycle\n");
      return 0;
    }
  }

  printf("No cycles\n");
  return 0;
}
