#include <iostream>
#include <vector>

long long func(std::vector<std::vector<long long> > &dp, const std::vector<long long> &a,
               int l, int r) {
  const long long INF = 1LL << 60;
  if (dp[l][r] > -1) return dp[l][r];
  long long res = INF;
  for (int i = l; i < r; ++i) {
    res = std::min(res, func(dp, a, l, i) + func(dp, a, i + 1, r));
  }
  res += a[r];
  if (l > 0) res -= a[l - 1];
  return dp[l][r] = res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];

  std::vector<std::vector<long long> > dp(n, std::vector<long long>(n, -1LL));
  for (int i = 0; i < n; ++i) dp[i][i] = a[i];
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  
  std::cout << func(dp, a, 0, n - 1) - a[n - 1] << std::endl;
  return 0;
}
