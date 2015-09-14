#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > adj;
vector<bool> visited, rec_stack;

bool check(int v, int parent = -1) {
  if ( ! visited[v]) {
    rec_stack[v] = visited[v] = true;

    for (int i: adj[v]) {
      if ( ! visited[i] && check(i, v)) {
        return true;
      }

      if (rec_stack[i] && i != parent) {
        return true;
      }
    }
  }

  return rec_stack[v] = false;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  adj.resize(n), visited.resize(n), rec_stack.resize(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;
    adj[u].push_back(v), adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) {
    if (check(i)) {
      printf("There is a cycle\n");
      return 0;
    }
  }

  printf("No cycles\n");
  return 0;
}
