#include <iostream>
#include <vector>

int main() {
  const long long MOD = 1000000007LL;
  int k;
  std::cin >> k;
  if (k % 9LL > 0LL) { std::cout << 0 << std::endl; return 0; }

  std::vector<long long> dp(k + 1, 0);
  ++dp[0];
  for (int i = 1; i <= k; ++i) {
    for (int j = std::max(0, i - 9); j < i; ++j) dp[i] = (dp[i] + dp[j]) % MOD;
  }  

  std::cout << dp[k] << std::endl;
  return 0;  
}
