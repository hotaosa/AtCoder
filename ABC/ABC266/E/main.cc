#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<double> dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      dp[i] += 1./6. * max(dp[i - 1], double(j));
    }
  }

  printf("%.10f\n", dp[n]);
  return 0;
}
