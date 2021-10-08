#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int> > &graph, std::vector<int> &dist, int v, int par) {
  for (int nv : graph[v]) {
    if (nv != par) {
      dist[nv] = dist[v] + 1;
      dfs(graph, dist, nv, v);
    }
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  std::vector<int> dist(n, -1);
  dist[0] = 0;
  dfs(graph, dist, 0, -1);

  int ma = 0;
  for (int i = 1; i < n; ++i) if (dist[i] > dist[ma]) ma = i;

  dist.assign(n, -1);
  dist[ma] = 0;
  dfs(graph, dist, ma, -1);

  int res = 0;
  for (int i = 0; i < n; ++i) res = std::max(res, dist[i]);
  std::cout << ++res << std::endl;
  return 0;
}
