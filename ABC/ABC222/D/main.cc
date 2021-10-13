#include <iostream>
#include <vector>

int main() {
  constexpr long long MOD = 998244353LL;
  auto modadd = [&MOD](long long &a, long long b) { a = (a + b) % MOD; };
  
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  for (int i = 0; i < n; ++i) std::cin >> b[i];

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(3001, 0LL));
  dp[0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 3000; ++j) modadd(dp[i - 1][j], dp[i - 1][j - 1]);
    for (int j = a[i - 1]; j <= b[i - 1]; ++j) dp[i][j] = dp[i - 1][j];
  }

  long long res = 0LL;
  for (int i = a.back(); i <= b.back(); ++i) modadd(res, dp[n][i]);
  std::cout << res << std::endl;
  return 0;  
}
