#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> res;
  std::vector<int> cur;
  auto Dfs = [&](auto self, int x) -> void {
    cur.emplace_back(x);
    int rem = n - std::size(cur);
    if (rem == 0) {
      res.emplace_back(cur);
    } else {
      for (int nx = x + 10; nx + 10 * (rem - 1) <= m; ++nx) {
        self(self, nx);
      }
    }
    cur.pop_back();
  };

  for (int s = 1; s <= m - 10 * (n - 1); ++s) {
    Dfs(Dfs, s);
  }

  std::cout << std::size(res) << "\n";
  for (auto &v : res) {
    for (std::size_t i = 0; i < std::size(v); ++i) {
      std::cout << v[i] << (i == std::size(v) - 1 ? '\n' : ' ');
    }
  }

  return 0;
}