#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < m; ++i) std::cin >> b[i];

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int res = 1 << 30;
  for (int i = 0; i < n; ++i) {
    auto pb = std::lower_bound(b.begin(), b.end(), a[i]);
    res = std::min(res, std::abs(a[i] - *pb));
    if (pb != b.begin()) res = std::min(res, std::abs(a[i] - *(--pb)));
  }

  std::cout << res << std::endl;
  return 0;
}
