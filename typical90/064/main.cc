#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<long long> diff(n - 1);
  for (int i = 0; i < n - 1; ++i) diff[i] = a[i + 1] - a[i];

  long long unconv = 0LL;
  for (int i = 0; i < n - 1; ++i) unconv += std::abs(diff[i]);

  for (int i = 0; i < q; ++i) {
    int l, r;
    long long v;
    std::cin >> l >> r >> v;
    --l;
    --r;
    if (l > 0) {
      unconv += std::abs(diff[l - 1] + v) - std::abs(diff[l - 1]);
      diff[l - 1] += v;
    }
    if (r < n - 1) {
      unconv += std::abs(diff[r] - v) - std::abs(diff[r]);
      diff[r] -= v;
    }
    std::cout << unconv << std::endl;
  }
  return 0;  
}
