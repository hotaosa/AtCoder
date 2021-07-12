#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n, s;
  std::cin >> n >> s;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i] >> b[i];

  std::vector<std::vector<int> > dp(n + 1, std::vector<int>(s + 1, -1));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < s; ++j) {
      if (dp[i][j] == -1) continue;
      if (j + a[i + 1] <= s) dp[i + 1][j + a[i + 1]] = 0;
      if (j + b[i + 1] <= s) dp[i + 1][j + b[i + 1]] = 1;
    }
  }

  if (dp[n][s] == -1) { std::cout << "Impossible" << std::endl; return 0; }
  std::string res = "";
  int cur = s;
  for (int i = n; i >= 1; --i) {
    if (dp[i][cur] == 0) {
      res += 'A';
      cur -= a[i];
    }
    else {
      res += 'B';
      cur -= b[i];
    }
  }

  std::reverse(res.begin(), res.end());
  std::cout << res << std::endl;
  return 0;
}
