#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];
  std::vector<long long> sum(n + 1, 0LL);
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + v[i - 1];

  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (*std::lower_bound(sum.begin(), sum.end(), n + sum[i - 1]) == n + sum[i - 1]) ++res;
  }
  std::cout << res << std::endl;
  return 0;
}
