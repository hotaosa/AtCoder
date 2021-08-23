#include <iostream>
#include <string>
#include <vector>

using vl = std::vector<long long>;
using vvl = std::vector<vl>;
using vvvl = std::vector<vvl>;

int main() {
  const long long MOD = 998244353LL;
  
  int n;
  std::string s;
  std::cin >> n >> s;

  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i) nums[i] = s[i] - 'A';

  auto add = [&](long long &a, long long b) -> void {
    a = (a + b) % MOD;
  };

  vvvl dp(n, vvl(1 << 10, vl(10, 0LL)));
  for (int i = 0; i < n - 1; ++i) {
    int cur = nums[i];
    int nx = nums[i + 1];
    ++dp[i][1 << cur][cur];
    for (int j = 0; j < (1 << 10); ++j) {
      for (int k = 0; k < 10; ++k) {
        add(dp[i + 1][j][k], dp[i][j][k]);
        if (k == nx || !(j & (1 << nx))) {
          add(dp[i + 1][j | (1 << nx)][nx], dp[i][j][k]);
        }
      }
    }
  }
  ++dp[n - 1][1 << nums[n - 1]][nums[n - 1]];

  long long res = 0LL;
  for (int j = 0; j < (1 << 10); ++j) {
    for (int k = 0; k < 10; ++k) {
      add(res, dp[n - 1][j][k]);
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
