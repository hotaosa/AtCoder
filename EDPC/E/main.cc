#include <iostream>
#include <vector>

void chmin(long long &a, long long b) { a = std::min(a, b); }
void chmax(int &a, int b) { a = std::max(a, b); }

int main() {
  const long long INF = 1LL << 60;
  int n;
  long long w;
  std::cin >> n >> w;

  std::vector<long long> weight(n + 1);
  std::vector<int> value(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    std::cin >> weight[i] >> value[i];
    sum += value[i];
  }

  std::vector<std::vector<long long> > dp(n + 1, std::vector<long long>(sum + 1, INF));
  dp[0][0] = 0LL;

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= sum; ++j) {
      chmin(dp[i][j], dp[i - 1][j]);
      if (j - value[i] >= 0) chmin(dp[i][j], dp[i - 1][j - value[i]] + weight[i]);
    }
  }

  int res = 0;
  for (int i = 1; i <= sum; ++i) {
    if (dp[n][i] <= w) chmax(res, i);
  }

  std::cout << res << std::endl;
  return 0;  
}
