#include <iostream>
#include <string>
#include <vector>

using vv = std::vector<std::vector<long long> >;

std::string func(int a, int b, long long k, const vv &dp) {
  if (a == 0) return std::string(b, 'b');
  if (b == 0) return std::string(a, 'a');
  if (k <= dp[a - 1][b]) return std::string("a") + func(a - 1, b, k, dp);
  else return std::string("b") + func(a, b - 1, k - dp[a - 1][b], dp);
}

int main() {
  int a, b;
  long long k;
  std::cin >> a >> b >> k;

  vv dp(a + 1, std::vector<long long>(b + 1, 0LL));
  dp[0][0] = 1;

  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      if (i > 0) dp[i][j] += dp[i - 1][j];
      if (j > 0) dp[i][j] += dp[i][j - 1];
    }
  }

  std::cout << func(a, b, k, dp) << std::endl;
  return 0;  
}
