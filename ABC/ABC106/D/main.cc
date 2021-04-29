#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<std::vector<int>> vv(n);
  for (int i = 0; i < m; ++i) {
    int l, r;
    std::cin >> l >> r;
    vv[--r].push_back(--l);
  }

  for (int i = 0; i < n; ++i) std::sort(vv[i].begin(), vv[i].end());

  for (int i = 0; i < q; ++i) {
    int p, q;
    std::cin >> p >> q;
    --p; --q;
    int res = 0;
    for (int i = 0; i <= q; ++i) {
      res += vv[i].end() - std::lower_bound(vv[i].begin(), vv[i].end(), p);
    }
    std::cout << res << std::endl;
  }

  return 0;
}
