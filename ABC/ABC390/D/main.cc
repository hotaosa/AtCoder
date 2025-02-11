#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<long long> a(n);
  for (auto &e : a) std::cin >> e;

  std::vector<long long> s;
  std::vector<long long> v(n, 0);
  auto Func = [&](auto self, int i) -> void {
    if (i == n) {
      s.emplace_back(std::accumulate(
          v.begin(), v.end(), 0LL,
          [](long long acc, long long nx) { return acc ^ nx; }));
      return;
    }
    for (int j = 0;; ++j) {
      v[j] += a[i];
      self(self, i + 1);
      v[j] -= a[i];
      if (v[j] == 0) break;
    }
  };

  Func(Func, 0);
  std::sort(s.begin(), s.end());
  std::cout << std::distance(s.begin(), std::unique(s.begin(), s.end()))
            << "\n";
  return 0;
}