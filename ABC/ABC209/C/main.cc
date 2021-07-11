#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const long long MOD = 1000000007LL;
  int n;
  std::cin >> n;
  std::vector<long long> c(n);
  for (int i = 0; i < n; ++i) std::cin >> c[i];

  std::sort(c.begin(), c.end());
  long long res = 1LL;
  for (int i = 0; i < n; ++i) {
    res = (res * (c[i] - i)) % MOD;
  }

  std::cout << res << std::endl;
  return 0;  
}
