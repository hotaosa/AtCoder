#include <iostream>
#include <string>
#include <vector>

int main() {
  const long long MOD = 1000000007LL;
  std::string s;
  std::cin >> s;
  int n = (int)s.length();

  std::vector<std::vector<int> > next(n + 1, std::vector<int>(26, n));
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) next[i][j] = next[i + 1][j];
    next[i][s[i] - 'a'] = i;
  }

  std::vector<long long> dp(n, 0LL);
  for (int j = 0; j < 26; ++j) if (next[0][j] < n) dp[next[0][j]] = 1LL;
  
  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < 26; ++j) {
      int nx = next[i + 2][j];
      if (nx < n) dp[nx] = (dp[nx] + dp[i]) % MOD;
    }
  }

  long long res = 0LL;
  for (int i = 0; i < n; ++i) res = (res + dp[i]) % MOD;
  std::cout << res << std::endl;

  return 0;  
}
