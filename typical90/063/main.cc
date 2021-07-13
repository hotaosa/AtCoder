#include <iostream>
#include <vector>

int main() {
  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int> > p(h, std::vector<int>(w));
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) std::cin >> p[i][j];

  int res = 0;
  for (int bit = 1; bit < (1 << h); ++bit) {
    std::vector<int> cnt(h * w + 1, 0);
    std::vector<int> row;
    for (int i = 0; i < h; ++i) if (bit & (1 << i)) row.push_back(i);
    for (int j = 0; j < w; ++j) {
      bool all_same = true;
      for (int i = 0; i < (int)row.size() - 1 && all_same; ++i) {
        if (p[row[i]][j] != p[row[i + 1]][j]) all_same = false;
      }
      if (all_same) cnt[p[row[0]][j]] += row.size();
    }
    for (int c : cnt) res = std::max(res, c);
  }

  std::cout << res << std::endl;
  return 0;
}
