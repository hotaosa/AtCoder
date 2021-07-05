#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  std::vector<std::vector<int> > dp(s.length() + 1, std::vector<int>(t.length() + 1, 0));

  for (int i = 1; i <= (int)s.length(); ++i) {
    for (int j = 1; j <= (int)t.length(); ++j) {
      if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  
  int len = dp[s.length()][t.length()];
  std::string res(len, 'z');

  --len;
  int i = s.length();
  int j = t.length();
  while (len >= 0) {
    if (s[i - 1] == t[j - 1]) {
      res[len] = s[i - 1];
      --i;
      --j;
      --len;
    } else if (dp[i][j] == dp[i - 1][j]) {
      --i;
    } else --j;
  }

  std::cout << res << std::endl;
  return 0;
}
