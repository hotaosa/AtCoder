#include <iostream>
#include <vector>

int main() {
  const int SIZ = 1000;
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > cnt(SIZ + 1, std::vector<int>(SIZ + 1, 0));

  for (int i = 0; i < n; ++i) {
    int lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;
    ++cnt[lx][ly];
    --cnt[lx][ry];
    --cnt[rx][ly];
    ++cnt[rx][ry];
  }

  for (int i = 0; i <= SIZ; ++i) {
    for (int j = 1; j <= SIZ; ++j) {
      cnt[i][j] += cnt[i][j - 1];
    }
  }
  for (int j = 0; j <= SIZ; ++j) {
    for (int i = 1; i <= SIZ; ++i) {
      cnt[i][j] += cnt[i - 1][j];
    }
  }

  std::vector<int> res(n + 1, 0);
  for (int i = 0; i <= SIZ; ++i) {
    for (int j = 0; j <= SIZ; ++j) {
      ++res[cnt[i][j]];
    }
  }

  for (int i = 1; i <= n; ++i) std::cout << res[i] << std::endl;
  return 0;  
}
