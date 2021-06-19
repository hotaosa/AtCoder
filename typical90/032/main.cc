#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const int INF = 1 << 30;
  
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > time(n);
  std::vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    order[i] = i;
    for (int j = 0; j < n; ++j) {
      int a;
      std::cin >> a;
      time[i].push_back(a);
    }
  }

  std::vector<std::vector<bool> > dislike(n, std::vector<bool>(n, false));
  int m;
  std::cin >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    dislike[x][y] = dislike[y][x] = true;
  }

  int res = INF;
  do {
    bool can = true;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      int runner = order[i];
      t += time[runner][i];
      if (i < n - 1) {
        int next = order[i + 1];
        if (dislike[runner][next]) can = false;
      }
    }
    if (can) res = std::min(res, t);
  } while (std::next_permutation(order.begin(), order.end()));

  if (res == INF) res = -1;
  std::cout << res << std::endl;
  return 0;
}
