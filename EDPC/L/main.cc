#include <iostream>
#include <vector>

const long long INF = 1LL << 60;
int n;

void chmax(long long &a, long long b) { a = std::max(a, b); }
void chmin(long long &a, long long b) { a = std::min(a, b); }

long long func(std::vector<std::vector<long long> > &dp,
               const std::vector<long long> &a, int i, int j) {
  if (dp[i][j] < INF && dp[i][j] > -INF) return dp[i][j];
  if ((i + n - 1 - j) & 1) {
    //minimize
    chmin(dp[i][j], func(dp, a, i + 1, j) - a[i]);
    chmin(dp[i][j], func(dp, a, i, j - 1) - a[j]);
    return dp[i][j];
  } else {
    //maximize
    chmax(dp[i][j], func(dp, a, i + 1, j) + a[i]);
    chmax(dp[i][j], func(dp, a, i, j - 1) + a[j]);
    return dp[i][j];
  }
}

int main() {
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<std::vector<long long> > dp(n, std::vector<long long>(n));
  
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      dp[i][j] = ((i + n - 1 - j) & 1 ? INF : -INF);
    }
  }

  for (int i = 0; i < n; ++i) dp[i][i] = (n & 1 ? a[i] : 0LL - a[i]);

  /*
  //test
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << dp[i][j] << ", ";
    }
    std::cout << std::endl;
  }
  */

  std::cout << func(dp, a, 0, n - 1) << std::endl;
  return 0;
}
