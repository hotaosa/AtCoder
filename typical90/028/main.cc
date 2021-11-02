#include <iostream>
#include <vector>

int main() {
  constexpr int SIZE = 1001;
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > cnt(SIZE, std::vector<int>(SIZE, 0));
  for (int i = 0; i < n; ++i) {
    int lx, ly, rx, ry;
    std::cin >> lx >> ly >> rx >> ry;
    ++cnt[lx][ly];
    --cnt[rx][ly];
    --cnt[lx][ry];
    ++cnt[rx][ry];
  }

  for (int i = 0; i < SIZE; ++i) for (int j = 1; j < SIZE; ++j) cnt[i][j] += cnt[i][j - 1];
  for (int j = 0; j < SIZE; ++j) for (int i = 1; i < SIZE; ++i) cnt[i][j] += cnt[i - 1][j];

  std::vector<int> res(n + 1, 0);
  for (int i = 0; i < SIZE; ++i) for (int j = 0; j < SIZE; ++j) ++res[cnt[i][j]];
  for (int i = 1; i <= n; ++i) std::cout << res[i] << std::endl;
  return 0;  
}
