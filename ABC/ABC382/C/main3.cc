#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n);
  for (auto &e : a) std::cin >> e;

  std::vector<std::pair<int, int>> b;
  for (int i = 0; i < m; ++i) {
    int x;
    std::cin >> x;
    b.emplace_back(x, i);
  }
  std::sort(std::begin(b), std::end(b));

  std::vector<int> res(m, -1);
  for (int i = 0; i < n; ++i) {
    while (!std::empty(b) && b.back().first >= a[i]) {
      res[b.back().second] = i;
      b.pop_back();
    }
  }

  for (int r : res) {
    std::cout << (r >= 0 ? r + 1 : -1) << "\n";
  }

  return 0;
}