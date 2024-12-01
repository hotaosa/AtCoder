#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<int> a(n), b(m);
  for (auto &e : a) {
    std::cin >> e;
    e = -e;
  }
  for (auto &e : b) {
    std::cin >> e;
    e = -e;
  }

  for (int i = 1; i < n; ++i) {
    a[i] = std::max(a[i], a[i - 1]);
  }

  for (int x : b) {
    auto it = std::lower_bound(std::begin(a), std::end(a), x);
    if (it != std::end(a)) {
      std::cout << std::distance(std::begin(a), it) + 1 << "\n";
    } else {
      std::cout << "-1\n";
    }
  }

  return 0;
}