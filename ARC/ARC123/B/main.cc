#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  for (int i = 0; i < n; ++i) std::cin >> c[i];

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  std::sort(c.begin(), c.end());

  int res = 0;
  auto l_b = b.begin();
  auto l_c = c.begin();
  for (int i = 0; i < n; ++i) {
    l_b = std::upper_bound(l_b, b.end(), a[i]);
    if (l_b == b.end()) break;
    l_c = std::upper_bound(l_c, c.end(), *l_b);
    if (l_c == c.end()) break;
    ++l_b;
    ++l_c;
    ++res;
  }

  std::cout << res << std::endl;
  return 0;
}
