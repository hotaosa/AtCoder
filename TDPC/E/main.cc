#include <iostream>
#include <string>
#include <vector>

using vll = std::vector<long long>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;

int main() {
  const long long MOD = 1000000007LL;
  int d;
  std::string s;
  std::cin >> d >> s;
  int len = (int)s.length();
  std::vector<int> num(len, 0);
  for (int i = 0; i < len; ++i) num[i] = s[i] - '0';

  vvvll dp(len + 1, vvll(d, vll(2, 0LL)));
  dp[0][0][0] = 1;
  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < d; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int n = 0; n <= 9; ++n) {
          if (k == 0 && n > num[i]) continue;
          int nj = (j + n) % d;
          int nk = 1;
          if (k == 0 && n == num[i]) nk = 0;
          dp[i + 1][nj][nk] = (dp[i + 1][nj][nk] + dp[i][j][k]) % MOD;
        }
      }
    }
  }

  long long res = dp[len][0][1] + dp[len][0][0] - 1LL;
  if (res < 0) res += MOD;
  std::cout << res << std::endl;
  return 0;  
}

