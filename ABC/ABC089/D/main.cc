#include <iostream>
#include <vector>

int main() {
  int h, w, d;
  std::cin >> h >> w >> d;
  std::vector<std::pair<int, int>> place(h * w + 1);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int a;
      std::cin >> a;
      place[a] = std::make_pair(i, j);
    }
  }
  std::vector<int> mp(h * w + 1, 0);
  for (int i = 1; i <= h * w; ++i) {
    if (i <= d) continue;
    int x1 = place[i - d].first;
    int y1 = place[i - d].second;
    int x2 = place[i].first;
    int y2 = place[i].second;
    mp[i] = mp[i - d] + std::abs(x1 - x2) + std::abs(y1 - y2);
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int l, r;
    std::cin >> l >> r;
    std::cout << mp[r] - mp[l] << std::endl;
  }
  return 0;
}
