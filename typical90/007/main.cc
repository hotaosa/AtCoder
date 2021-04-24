#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());

  int q;
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int b;
    std::cin >> b;
    auto p = std::lower_bound(a.begin(), a.end(), b);
    if (p == a.end()) std::cout << b - *(--p) << std::endl;
    else {
      int dis = *p - b;
      if (*p != a[0]) {dis = std::min(dis, b - *(--p)); }
      std::cout << dis << std::endl;
    }
  }
  return 0;    
}
