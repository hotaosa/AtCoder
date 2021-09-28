#include <iostream>
#include <vector>

int main() {
  constexpr long long MOD = 998244353LL;
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<std::vector<long long> > dp(n, std::vector<long long>(10, 0LL));
  dp[0][a[0]] = 1LL;

  auto modadd = [&](long long &a, long long b) -> void {
    a = (a + b) % MOD;
  };

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (dp[i][j] > 0LL) {
        modadd(dp[i + 1][(j + a[i + 1]) % 10], dp[i][j]);
        modadd(dp[i + 1][(j * a[i + 1]) % 10], dp[i][j]);
      }
    }
  }

  for (int i = 0; i < 10; ++i) std::cout << dp[n - 1][i] << std::endl;
  return 0;  
}
