#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::sort(a.begin(), a.end());
  std::vector<long long> cnt(n);
  for (int i = 0; i < n; ++i) cnt[i] = a[i] - i - 1;

  for (int i = 0; i < q; ++i) {
    long long k;
    std::cin >> k;
    auto p = std::lower_bound(cnt.begin(), cnt.end(), k);
    if (p == cnt.end()) std::cout << k + n << std::endl;
    else std::cout << a[p - cnt.begin()] - *p + k - 1 << std::endl;    
  }

  return 0;  
}
