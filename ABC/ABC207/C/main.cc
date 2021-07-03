#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> vp;
  for (int i = 0; i < n; ++i) {
    int t, l, r;
    std::cin >> t >> l >> r;
    l += l;
    r += r;
    if (!(t & 1)) --r;
    if (t > 2) ++l;
    vp.push_back(std::make_pair(l, r));
  }

  auto overlap = [&](int i, int j) -> bool {
    if (vp[i].second < vp[j].first) return false;
    if (vp[i].first > vp[j].second) return false;
    return true;
  };
  
  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (overlap(i, j)) ++res;
    }
  }

  std::cout << res << std::endl;
  return 0;
}
