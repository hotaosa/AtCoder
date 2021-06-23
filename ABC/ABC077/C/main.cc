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

  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    auto pa = std::lower_bound(a.begin(), a.end(), b[i]);
    auto pc = std::upper_bound(c.begin(), c.end(), b[i]);
    res += (pa - a.begin()) * (c.end() - pc);
  }
  
  std::cout << res << std::endl;
  return 0;  
}
