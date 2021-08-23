#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > vp;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    vp.push_back(std::make_pair(x, y));
  }
  std::sort(vp.begin(), vp.end());

  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    x[i] = vp[i].first;
    y[i] = vp[i].second;
  }

  std::vector<int> y_mi(n), y_ma(n);
  y_mi[0] = y_ma[0] = y[0];
  for (int i = 1; i < n; ++i) {
    y_mi[i] = std::min(y_mi[i - 1], y[i]);
    y_ma[i] = std::max(y_ma[i - 1], y[i]);
  }

  auto judge = [&](int k) -> bool {
    for (int i = 1; i < n; ++i) {
      int id = std::upper_bound(x.begin(), x.end(), x[i] - k) - x.begin();
      if (--id < 0) continue;
      if (std::abs(y[i] - y_mi[id]) >= k || std::abs(y[i] - y_ma[id]) >= k) return true;
    }
    return false;
  };

  int l = 0, r = 1 << 30;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (judge(m)) l = m;
    else r = m;
  }

  std::cout << l << std::endl;
  return 0;  
}
