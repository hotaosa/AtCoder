#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>> &graph,
         std::vector<bool> &used, int v, int par, bool &tree) {
  used[v] = true;
  for (int nv : graph[v]) {
    if (nv == par) continue;
    if (used[nv]) { tree = false; continue; }
    dfs(graph, used, nv, v, tree);
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  int res = 0;
  std::vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    bool tree = true;
    if (used[i]) continue;
    dfs(graph, used, i, -1, tree);
    if (tree) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
