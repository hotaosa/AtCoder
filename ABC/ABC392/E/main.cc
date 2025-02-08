#include <iostream>
#include <set>
#include <tuple>
#include <vector>
//
#include <atcoder/dsu>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::tuple<int, int, int>> edges;

  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    if (uf.same(--u, --v)) {
      edges.emplace_back(i, u, v);
    } else {
      uf.merge(u, v);
    }
  }

  std::set<int> s;
  for (auto &&g : uf.groups()) {
    s.insert(uf.leader(g[0]));
  }

  std::vector<std::tuple<int, int, int>> res;
  while (std::size(s) > 1) {
    auto [i, u, v] = edges.back();
    edges.pop_back();
    auto it = s.find(uf.leader(u));
    if (it == s.end()) continue;
    auto it2 = it != s.begin() ? std::prev(it) : std::next(it);
    res.emplace_back(i, v, *it2);
    s.erase(uf.merge(*it, *it2) == *it ? *it2 : *it);
  }

  std::cout << std::size(res) << "\n";
  for (auto [i, u, v] : res) {
    std::cout << i + 1 << " " << u + 1 << " " << v + 1 << "\n";
  }

  return 0;
}