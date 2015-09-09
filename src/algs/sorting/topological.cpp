#include <cstdio>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

int main() {
  printf("How many tasks do you have?\n");
  int n, u, v;
  scanf("%d", &n);
  vector< vector<int> > graph(n);
  vector<int> indeg(n), nodes;
  queue<int> free;

  for (int i = 0; i < n - 1; ++i) {
    printf("Please type task ID and its dependency:\n");
    scanf("%d%d", &v, &u);
    --u, --v;
    ++indeg[v], graph[u].push_back(v);
  }

  for (int i = 0; i < n; ++i) {
    for (int adj_node: graph[i]) {
      printf("Task #%d depends on task #%d\n", adj_node + 1, i + 1);
    }
  }

  for (int i = 0; i < n; ++i) {
    if (indeg[i] == 0) {
      free.push(i);
    }
  }

  assert ( ! free.empty());

  while ( ! free.empty()) {
    int node = free.front();
    free.pop(), nodes.push_back(node);

    for (int adj_node: graph[node]) {
      --indeg[adj_node];

      if (indeg[adj_node] == 0) {
        free.push(adj_node);
      }
    }
  }

  assert((int) nodes.size() == n);

  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      printf("Then do task #%d\n", nodes[i] + 1);
    } else {
      printf("First, do task #%d\n", nodes[i] + 1);
    }
  }

  return 0;
}
