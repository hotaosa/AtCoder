#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  constexpr int INF = 1 << 30;
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) std::cin >> a[i][j];

  std::vector<std::vector<bool> > fr(n, std::vector<bool>(n, true));
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    fr[--a][--b] = false;
    fr[b][a] = false;
  }

  std::vector<int> order(n);
  for (int i = 0; i < n; ++i) order[i] = i;

  int res = INF;
  do {
    bool good = true;
    for (int i = 1; i < n; ++i) if (!fr[order[i - 1]][order[i]]) good = false;
    if (good) {
      int cur = 0;
      for (int i = 0; i < n; ++i) cur += a[order[i]][i];
      res = std::min(res, cur);
    }
  } while (std::next_permutation(order.begin(), order.end()));

  std::cout << (res < INF ? res : -1) << std::endl;
  return 0;  
}
