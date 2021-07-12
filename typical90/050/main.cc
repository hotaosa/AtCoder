#include <iostream>
#include <vector>

int main() {
  const long long MOD = 1000000007LL;
  int n, l;
  std::cin >> n >> l;
  std::vector<long long> dp(n + 1, 0LL);
  ++dp[0];

  for (int i = 0; i < n; ++i) {
    dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    if (i + l <= n) dp[i + l] = (dp[i + l] + dp[i]) % MOD;
  }
  std::cout << dp[n] << std::endl;
  return 0;
}
