#include <iostream>
#include <vector>

double func(std::vector<std::vector<std::vector<double> > > &dp, int c1, int c2, int c3, int n) {
  if (dp[c1][c2][c3] > 0.0) return dp[c1][c2][c3];
  double per1 = (double)c1 / n;
  double per2 = (double)c2 / n;
  double per3 = (double)c3 / n;
  double per0 = 1.0 - per1 - per2 - per3;

  double res = 1 / (1 - per0);
  if (c1 > 0) res += func(dp, c1 - 1, c2, c3, n) * per1 / (1 - per0);
  if (c2 > 0) res += func(dp, c1 + 1, c2 - 1, c3, n) * per2 / (1 - per0);
  if (c3 > 0) res += func(dp, c1, c2 + 1, c3 - 1, n) * per3 / (1 - per0);
  return dp[c1][c2][c3] = res;
}

int main() {
  int n;
  std::cin >> n;
  int c1 = 0, c2 = 0, c3 = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    std::cin >> a;
    if (a == 1) ++c1;
    else if (a == 2) ++c2;
    else ++c3;
  }

  std::vector<std::vector<std::vector<double> > > dp(n + 1,
                                                     std::vector<std::vector<double> >(n + 1,
                                                     std::vector<double>(n + 1, 0.0)));

  dp[1][0][0] = (double)n;
  printf("%.10f\n", func(dp, c1, c2, c3, n));
  return 0;
}
