#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> pos(n);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    pos[--a].emplace_back(i);
  }

  long long res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)pos[i].size(); ++j) {
      int left = j > 0 ? pos[i][j - 1] : -1;
      int right = n;
      if (i > 0 && !pos[i - 1].empty()) {
        auto it =
            std::lower_bound(pos[i - 1].begin(), pos[i - 1].end(), pos[i][j]);
        if (it != pos[i - 1].begin()) left = std::max(left, *std::prev(it));
        if (it != pos[i - 1].end()) right = std::min(right, *it);
      }
      res += (long long)(pos[i][j] - left) * (long long)(right - pos[i][j]);
    }
  }

  std::cout << res << "\n";
  return 0;
}