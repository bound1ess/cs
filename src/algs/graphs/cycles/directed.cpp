#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

vector< vector<int> > adj;
vector<bool> visited, rec_stack; // visited nodes and recursion stack

bool check(int v) {
  if ( ! visited[v]) {
    rec_stack[v] = visited[v] = true; // add to the stack; mark as visited

    for (int adj_v: adj[v]) {
      if ( ! visited[adj_v] && check(adj_v)) { // recursive call
        return true;
      }

      if (rec_stack[adj_v]) { // we found a "back edge"
        return true;
      }
    }
  }

  return rec_stack[v] = false; // exclude this vertex/node from the stack
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  visited.resize(n), rec_stack.resize(n), adj.resize(n);

  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u - 1].push_back(v - 1);
  }

  for (int i = 0; i < n; ++i) {
    if (check(i)) {
      printf("There is a loop :(\n");
      return 0;
    }
  }

  printf("DAG\n");
  return 0;
}
