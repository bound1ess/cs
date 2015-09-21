#include <cstdio>
#include <cassert>

const int INT_MAX = (1LL << 31) - 1; // 2^31 - 1 for signed 32-bit integers

// slow
inline int min_dist(int *dist, bool *spt, int n) {
  int min = INT_MAX, index = -1;
  for (int i = 0; i < n; ++i) {
    if ( ! spt[i] && dist[i] <= min) {
      index = i;
      min = dist[i];
    }
  }
  return index;
}

inline int* compute(int **g, int n) {
  int *dist = new int[n];
  bool *spt = new bool[n];
  for (int i = 0; i < n; ++i) {
    spt[i] = false;
    dist[i] = INT_MAX;
  }
  dist[0] = 0;
  for (int i = 0; i < n - 1; ++i) {
    int v = min_dist(dist, spt, n);
    spt[v] = true;
    for (int j = 0; j < n; ++j) {
      if ( ! spt[j] && g[v][j] != -1 && dist[v] != INT_MAX) {
        if (dist[v] + g[v][j] < dist[j]) {
          dist[j] = dist[v] + g[v][j];
        }
      }
    }
  }
  delete[] spt;
  return dist;
}

int main() {
  freopen("dijkstra_in.txt", "r", stdin);
  int n, m;
  scanf("%d%d", &n, &m);
  assert(n > 0);
  int **g = new int*[n];
  for (int i = 0; i < n; ++i) {
    g[i] = new int[n];
    for (int j = 0; j < n; ++j) {
      g[i][j] = -1;
    }
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    g[u - 1][v - 1] = w;
  }
  int *dist = compute(g, n);
  for (int i = 0; i < n; ++i) {
    printf("s(1, %d) = %d\n", i + 1, dist[i]);
  }
  delete[] dist;
  for (int i = 0; i < n; ++i) {
    delete[] g[i];
  }
  delete[] g;
  return 0;
}
