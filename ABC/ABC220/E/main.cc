#include <iostream>
#include <vector>

int main() {
  constexpr long long MOD = 998244353LL;
  auto modadd = [&MOD](long long &a, long long b) -> void { a = (a + b) % MOD; };
  
  int n, d;
  std::cin >> n >> d;

  std::vector<long long> pw(2 * n);
  pw[0] = 1LL;
  for (int i = 1; i < 2 * n; ++i) pw[i] = pw[i - 1] * 2LL % MOD;

  long long res = 0LL;
  for (int i = 0; i < n - 1; ++i) {
    if (i + d < n) modadd(res, pw[d] * pw[i]);
    if (d >= 2 && d < 2 * n) {
      int ma = std::min(n - 1 - i, d - 1);
      int mi = d - ma;
      modadd(res, pw[d - 2] * std::max(0, ma - mi + 1) % MOD * pw[i]);
    }
  }

  res = res * 2LL % MOD;
  std::cout << res << std::endl;    
  return 0;  
}
