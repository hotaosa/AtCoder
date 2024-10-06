#include <iostream>
#include <vector>

int main() {
  int n, k;
  std::cin >> n >> k;

  std::vector<int> r(n);
  for (auto &e : r) std::cin >> e;

  std::vector<std::vector<int>> res;
  std::vector<int> cur;
  auto Search = [&](auto self, int i, int sum) -> void {
    if (i == n) {
      if (sum % k == 0) {
        res.emplace_back(cur);
      }
      return;
    }

    for (int x = 1; x <= r[i]; ++x) {
      cur.emplace_back(x);
      self(self, i + 1, sum + x);
      cur.pop_back();
    }
  };
  Search(Search, 0, 0);

  for (const auto &v : res) {
    for (int i = 0; i < n; ++i) {
      std::cout << v[i] << (i == n - 1 ? '\n' : ' ');
    }
  }

  return 0;
}