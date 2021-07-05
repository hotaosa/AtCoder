#include <iostream>
#include <vector>


int main() {
  const long long INF = 1LL << 60;
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<long long> > dp(n, std::vector<long long>(n, INF));
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    std::cin >> a >> b >> c;
    dp[--a][--b] = c;
  }

  for (int v = 0; v < n; ++v) dp[v][v] = 0;
  long long res = 0LL;
  
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (dp[i][j] < INF) res += dp[i][j];
      }
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
