#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/dsu>

int main() {
  int n;
  std::cin >> n;

  std::vector<int> u(n - 1), v(n - 1), deg(n, 0);
  for (int i = 0; i < n - 1; ++i) {
    std::cin >> u[i] >> v[i];
    ++deg[--u[i]];
    ++deg[--v[i]];
  }

  std::vector<int> adj_deg2(n, 0);
  atcoder::dsu uf(n);
  for (int i = 0; i < n - 1; ++i) {
    if (deg[u[i]] == 2) ++adj_deg2[v[i]];
    if (deg[v[i]] == 2) ++adj_deg2[u[i]];
    if (deg[u[i]] == 3 && deg[v[i]] == 3) uf.merge(u[i], v[i]);
  }

  std::int64_t res = 0;
  for (auto &g : uf.groups()) {
    if (deg[g[0]] != 3) continue;
    std::int64_t count = std::accumulate(
        std::begin(g), std::end(g), 0,
        [&adj_deg2](std::int64_t acc, int v) { return acc + adj_deg2[v]; });

    res += count * (count - 1) / 2;
  }

  std::cout << res << "\n";
  return 0;
}