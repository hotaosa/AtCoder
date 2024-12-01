#include <iostream>
#include <set>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (auto &e : a) std::cin >> e;

  std::multiset<std::pair<int, int>> se;
  for (int i = 0; i < m; ++i) {
    int b;
    std::cin >> b;
    se.emplace(b, i);
  }

  std::vector<int> res(m, -1);
  for (int i = 0; i < n; ++i) {
    for (auto it = se.lower_bound({a[i], 0}); it != std::end(se);) {
      res[it->second] = i;
      it = se.erase(it);
    }
  }

  for (int r : res) {
    std::cout << (r >= 0 ? r + 1 : -1) << "\n";
  }
  return 0;
}