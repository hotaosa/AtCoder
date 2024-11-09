#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(m);
  std::vector<long long> a(m);
  for (auto &e : x) std::cin >> e;
  for (auto &e : a) std::cin >> e;

  if (*std::min_element(std::begin(x), std::end(x)) > 1) {
    std::cout << "-1\n";
    return 0;
  }

  if (*std::max_element(std::begin(x), std::end(x)) < n) {
    x.emplace_back(n);
    a.emplace_back(0);
  }

  if (std::accumulate(std::begin(a), std::end(a), 0LL) != n) {
    std::cout << "-1\n";
    return 0;
  }

  std::vector<std::size_t> order(std::size(x));
  std::iota(std::begin(order), std::end(order), 0);
  std::sort(std::begin(order), std::end(order),
            [&x](auto i, auto j) { return x[i] < x[j]; });

  long long res = 0;
  for (std::size_t i = 0; i < std::size(order) - 1; ++i) {
    const auto cur = order[i];
    const auto nx = order[i + 1];

    const long long diff = x[nx] - x[cur];
    if (a[cur] < diff) {
      std::cout << "-1\n";
      return 0;
    }
    res += diff * (diff - 1) / 2;
    res += (a[cur] - diff) * diff;
    a[nx] += a[cur] - diff;
  }

  std::cout << res << "\n";
  return 0;
}