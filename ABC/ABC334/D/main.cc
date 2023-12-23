#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> r(n);
  for (auto &e : r) std::cin >> e;
  std::sort(r.begin(), r.end());
  for (int i = 1; i < n; ++i) r[i] += r[i - 1];

  while (q--) {
    long long x;
    std::cin >> x;
    std::cout << std::upper_bound(r.begin(), r.end(), x) - r.begin() << std::endl;
  }

  return 0;
}