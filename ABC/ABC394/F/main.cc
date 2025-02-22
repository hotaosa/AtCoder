#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> deg(n, 0);
  std::vector<std::pair<int, int>> edges;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    edges.emplace_back(--u, --v);
    ++deg[u];
    ++deg[v];
  }

  std::vector g(n, std::vector<int>{});
  for (auto [u, v] : edges) {
    if (deg[u] >= 4 || deg[v] >= 4) {
      g[u].emplace_back(v);
      g[v].emplace_back(u);
    }
  }

  std::vector<bool> used(n, false);
  int res = -1;
  auto Dfs = [&](auto self, int u, int p) -> int {
    used[u] = true;
    if (g[u].size() < 4) return 1;
    std::vector<int> ch;
    for (int v : g[u]) {
      if (v == p) continue;
      ch.emplace_back(self(self, v, u));
    }
    std::sort(ch.rbegin(), ch.rend());
    if (ch.size() >= 4) {
      res = std::max(res, std::accumulate(ch.begin(), ch.begin() + 4, 1));
    }
    return std::accumulate(ch.begin(), ch.begin() + 3, 1);
  };

  for (int i = 0; i < n; ++i) {
    if (!used[i]) Dfs(Dfs, i, -1);
  }

  std::cout << res << "\n";
  return 0;
}