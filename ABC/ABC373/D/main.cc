#include <iostream>
#include <vector>

struct Edge {
  int to;
  long long w;
};

int main() {
  size_t n, m;
  std::cin >> n >> m;

  std::vector<std::vector<Edge>> graph(n);
  for (size_t i = 0; i < m; ++i) {
    int u, v;
    long long w;
    std::cin >> u >> v >> w;
    graph[--u].emplace_back(--v, w);
    graph[v].emplace_back(u, -w);
  }

  constexpr long long INF = 1LL << 60;
  std::vector<long long> res(n, INF);

  auto Walk = [&](auto self, int u, int par = -1) -> void {
    for (auto [v, w] : graph[u]) {
      if (v == par || res[v] != INF) continue;
      res[v] = res[u] + w;
      self(self, v, u);
    }
  };

  for (size_t i = 0; i < n; ++i) {
    if (res[i] == INF) {
      res[i] = 0;
      Walk(Walk, i);
    }
  }

  for (size_t i = 0; i < n; ++i) {
    std::cout << res[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}