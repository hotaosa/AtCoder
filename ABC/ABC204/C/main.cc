#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int> > &graph, int v, std::vector<bool> &used, int &res) {
  used[v] = true;
  ++res;
  for (int n_v : graph[v]) {
    if (used[n_v]) continue;
    dfs(graph, n_v, used, res);
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
  }

  int res = 0;
  for (int s = 0; s < n; ++s) {
    std::vector<bool> used(n, false);
    dfs(graph, s, used, res);
  }

  std::cout << res << std::endl;
  return 0;
}
