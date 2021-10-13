#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  long long res = 0LL;
  for (int i = 0; i < n; ++i) res += std::abs(a[i] - b[i]);
  std::cout << res << std::endl;
  return 0;
}
