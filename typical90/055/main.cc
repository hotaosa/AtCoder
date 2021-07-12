#include <iostream>
#include <vector>

int main() {
  int n;
  long long p, q;
  std::cin >> n >> p >> q;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  long long res = 0LL;
  for (int i = 0; i < n - 4; ++i) {
    long long mul = a[i] % p;
    for (int j = i + 1; j < n - 3; ++j) {
      long long mul2 = mul * a[j] % p;
      for (int k = j + 1; k < n - 2; ++k) {
        long long mul3 = mul2 * a[k] % p;
        for (int l = k + 1; l < n - 1; ++l) {
          long long mul4 = mul3 * a[l] % p;
          for (int m = l + 1; m < n; ++m) {
            long long mul5 = mul4 * a[m] % p;
            if (mul5 == q) ++res;
          }
        }
      }
    }
  }
  std::cout << res << std::endl;
  return 0;
}
