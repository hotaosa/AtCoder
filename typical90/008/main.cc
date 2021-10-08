#include <iostream>
#include <string>
#include <vector>

int main() {
  constexpr long long MOD = 1000000007LL;
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> v(n, 0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') v[i] = 1;
    else if (s[i] == 't') v[i] = 2;
    else if (s[i] == 'c') v[i] = 3;
    else if (s[i] == 'o') v[i] = 4;
    else if (s[i] == 'd') v[i] = 5;
    else if (s[i] == 'e') v[i] = 6;
    else if (s[i] == 'r') v[i] = 7;
  }

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(8, 0LL));
  dp[0][0] = 1LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= 7; ++j) dp[i][j] = dp[i - 1][j];
    if (v[i - 1] > 0) dp[i][v[i - 1]] = (dp[i][v[i - 1]] + dp[i][v[i - 1] - 1]) % MOD;
  }

  std::cout << dp[n][7] << std::endl;
  return 0;  
}
