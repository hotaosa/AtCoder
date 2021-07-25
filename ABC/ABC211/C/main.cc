#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
  const long long MOD = 1000000007LL;
  
  std::string s;
  std::cin >> s;
  int n = (int)s.length();

  std::map<char, int> ma;
  ma['c'] = 1;
  ma['h'] = 2;
  ma['o'] = 3;
  ma['k'] = 4;
  ma['u'] = 5;
  ma['d'] = 6;
  ma['a'] = 7;
  ma['i'] = 8;

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(9, 0LL));
  dp[0][0] = 1LL;
  if (s[0] == 'c') dp[0][1] = 1LL;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 9; ++j) dp[i][j] = dp[i - 1][j];
    if (ma[s[i]] > 0) dp[i][ma[s[i]]] = (dp[i][ma[s[i]]] + dp[i - 1][ma[s[i]] - 1]) % MOD;
  }

  std::cout << dp[n - 1][8] << std::endl;
  return 0;  
}
