#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  int n, w;
  std::cin >> n >> w;

  std::vector<std::vector<std::pair<int, int>>> blocks(w);
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    blocks[--x].emplace_back(y, i);
  }

  std::sort(std::begin(blocks), std::end(blocks),
            [](const auto& lhs, const auto& rhs) {
              return std::size(lhs) > std::size(rhs);
            });
  for (auto& b : blocks) std::sort(std::rbegin(b), std::rend(b));

  std::vector<int> res(n, 1000000001);
  while (!empty(blocks.back())) {
    int max_val = std::accumulate(
        std::begin(blocks), std::end(blocks), 0,
        [](int acc, const auto& b) { return std::max(acc, b.back().first); });
    for (int i = 0; i < w; ++i) {
      auto [val, idx] = blocks[i].back();
      res[idx] = max_val;
      blocks[i].pop_back();
    }
  }

  int q;
  std::cin >> q;
  while (q--) {
    int t, a;
    std::cin >> t >> a;
    std::cout << (res[--a] > t ? "Yes\n" : "No\n");
  }

  return 0;
}