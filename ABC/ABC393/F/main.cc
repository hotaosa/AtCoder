#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (auto &e : a) std::cin >> e;

  std::vector<int> r(q), x(q);
  for (int i = 0; i < q; ++i) {
    std::cin >> r[i] >> x[i];
  }

  std::vector<int> o(q);
  std::iota(std::begin(o), std::end(o), 0);
  std::sort(std::begin(o), std::end(o),
            [&r](int i, int j) { return r[i] < r[j]; });

  std::vector<int> v, res(q);
  int idx = 0;
  for (int i : o) {
    while (idx < r[i]) {
      auto it = std::lower_bound(std::begin(v), std::end(v), a[idx]);
      if (it == std::end(v)) {
        v.emplace_back(a[idx]);
      } else {
        *it = a[idx];
      }
      ++idx;
    }
    auto it = std::upper_bound(std::begin(v), std::end(v), x[i]);
    res[i] = std::distance(std::begin(v), it);
  }

  for (int r : res) std::cout << r << "\n";
  return 0;
}
