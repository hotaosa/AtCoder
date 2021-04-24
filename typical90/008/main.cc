#include <iostream>
#include <string>
#include <vector>


int main() {
  const long long MOD = 1000000007LL;
  
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(8, 0));
  dp[0][0] = 1LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 8; ++j) dp[i + 1][j] += dp[i][j];
    if (s[i] == 'a') dp[i + 1][1] = (dp[i + 1][1] + dp[i][0]) % MOD;
    else if (s[i] == 't') dp[i + 1][2] = (dp[i + 1][2] + dp[i][1]) % MOD;
    else if (s[i] == 'c') dp[i + 1][3] = (dp[i + 1][3] + dp[i][2]) % MOD;
    else if (s[i] == 'o') dp[i + 1][4] = (dp[i + 1][4] + dp[i][3]) % MOD;
    else if (s[i] == 'd') dp[i + 1][5] = (dp[i + 1][5] + dp[i][4]) % MOD;
    else if (s[i] == 'e') dp[i + 1][6] = (dp[i + 1][6] + dp[i][5]) % MOD;
    else if (s[i] == 'r') dp[i + 1][7] = (dp[i + 1][7] + dp[i][6]) % MOD;
  }
  std::cout << dp[n][7] << std::endl;
  return 0;
}
