#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  const long long MOD = 1000000007LL;
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::sort(a.begin(), a.end());
  long long res = a[0] + 1LL;
  for (int i = 1; i < n; ++i) {
    res = res * (a[i] - a[i - 1] + 1LL) % MOD;
  }
  std::cout << res << std::endl;
  return 0;  
}
