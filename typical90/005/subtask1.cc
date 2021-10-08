#include <iostream>
#include <vector>

constexpr long long MOD = 1000000007LL;

void modadd(long long &a, long long b) { a = (a + b) % MOD; }

int main() {
  int n, b, k;
  std::cin >> n >> b >> k;

  std::vector<int> usable(k);
  for (int i = 0; i < k; ++i) std::cin >> usable[i];

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(b, 0LL));
  dp[0][0] = 1LL;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < b; ++j) {
      for (int nx : usable) {
        modadd(dp[i + 1][(j * 10 + nx) % b], dp[i][j]);
      }
    }
  }

  std::cout << dp[n][0] << std::endl;
  return 0;  
}
