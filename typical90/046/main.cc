#include <iostream>
#include <vector>

int main() {
  const int MOD = 46;
  int n;
  std::cin >> n;

  std::vector<long long> cnt_a(MOD, 0), cnt_b(MOD, 0), cnt_c(MOD, 0);
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    ++cnt_a[a % MOD];
  }
  for (int i = 0; i < n; ++i) {
    int b;
    std::cin >> b;
    ++cnt_b[b % MOD];
  }
  for (int i = 0; i < n; ++i) {
    int c;
    std::cin >> c;
    ++cnt_c[c % MOD];
  }

  long long res = 0LL;
  for (int i = 0; i < MOD; ++i) {
    long long ca = cnt_a[i];
    for (int j = 0; j < MOD; ++j) {
      long long cb = cnt_b[j];
      for (int k = 0; k < MOD; ++k) {
        long long cc = cnt_c[k];
        if ((i + j + k) % MOD == 0) res += ca * cb * cc;
      }
    }
  }

  std::cout << res << std::endl;
  return 0;
}
