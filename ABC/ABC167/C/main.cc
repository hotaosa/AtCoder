#include <iostream>
#include <vector>

int main() {
  const int INF = 1 << 30;
  int n, m, x;
  std::cin >> n >> m >> x;
  std::vector<int> c(n);
  std::vector<std::vector<int> > a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    for (int j = 0; j < m; ++j) std::cin >> a[i][j];
  }

  int res = INF;
  for (int bit = 1; bit < (1 << n); ++bit) {
    std::vector<int> master(m, 0);
    int cost = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {
        cost += c[i];
        for (int j = 0; j < m; ++j) master[j] += a[i][j];
      }
    }

    bool achieved = true;
    for (int i = 0; i < m; ++i) if (master[i] < x) achieved = false;
    if (achieved) res = std::min(res, cost);
  }

  std::cout << (res < INF ? res : -1) << std::endl;
  return 0;
}
