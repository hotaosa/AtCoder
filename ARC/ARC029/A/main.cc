#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> t(n);
  for (int i = 0; i < n; ++i) std::cin >> t[i];

  int res = 1 << 30;
  for (int bit = 0; bit < (1 << n); ++bit) {
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) r += t[i];
      else l += t[i];
    }
    res = std::min(res, std::max(l, r));    
  }
  std::cout << res << std::endl;
  return 0;
}
