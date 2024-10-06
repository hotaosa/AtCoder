#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> k(n);
  for (auto &e : k) std::cin >> e;

  int res = 1 << 30;
  for (unsigned int b = 0; b < (1u << n); ++b) {
    int x = 0, y = 0;
    for (std::size_t i = 0; i < std::size(k); ++i) {
      (b >> i & 1 ? x : y) += k[i];
    }
    res = std::min(res, std::max(x, y));
  }

  std::cout << res << "\n";
  return 0;
}