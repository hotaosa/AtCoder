#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, x;
  cin >> n >> x;

  vector<long long> w(n);
  vector<int> v(n);
  int v_sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> v[i];
    v_sum += v[i];
  }

  const long long INF = 1LL << 60;
  vector<vector<long long> > dp(n + 1, vector<long long>(v_sum + 1, INF));
  dp[0][0] = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= v_sum; ++j) {
      chmin(dp[i + 1][j], dp[i][j]);
      if (j + v[i] <= v_sum) chmin(dp[i + 1][j + v[i]], dp[i][j] + w[i]);
    }
  }

  int res = 0;
  for (int i = 0; i <= v_sum; ++i) {
    if (dp[n][i] <= x) res = i;
  }
  cout << res << endl;
  
  return 0;
}
