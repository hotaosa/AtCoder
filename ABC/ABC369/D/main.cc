#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void ChangeMax(ll &a, ll b) { a = max(a, b); }

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;

  vector dp(n + 1, vector<ll>(2, -1));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (dp[i][j] < 0) continue;
      ChangeMax(dp[i + 1][j], dp[i][j]);
      ChangeMax(dp[i + 1][j ^ 1], dp[i][j] + a[i] * (j + 1));
    }
  }

  auto res = max(dp[n][0], dp[n][1]);
  cout << res << endl;

  return 0;
}