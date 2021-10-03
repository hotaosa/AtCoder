#include <iostream>

int main() {
  constexpr long long MOD = 1000000007LL;
  int n;
  std::cin >> n;
  long long res = 0LL;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    int aa = a, digit = 0;
    while (aa) {
      ++digit;
      aa /= 10;
    }
    for (int i = 0; i < digit; ++i) res = res * 10LL % MOD;
    res = (res + a) % MOD;
  }
  std::cout << res <<std::endl;
  return 0;
}
