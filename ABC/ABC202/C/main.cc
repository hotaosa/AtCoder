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

  std::vector<int> bc;
  for (int i = 0; i < n; ++i) bc.push_back(b[c[i] - 1]);
  std::sort(bc.begin(), bc.end());

  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    res += std::upper_bound(bc.begin(), bc.end(), a[i]) - std::lower_bound(bc.begin(), bc.end(), a[i]);
  }

  std::cout << res << std::endl;
  return 0;  
}
