#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> a(n), b(n), c(n);
  int sum_a = 0, sum_b = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    sum_a += a[i];
    sum_b += b[i];
  }

  vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(sum_a + 1, vector<int>(sum_b + 1, INF)));
  dp[0][0][0] = 0;

  for (int i = 0; i < n;++i) {
    for (int j = 0; j <= sum_a; ++j) {
      for (int k = 0; k <= sum_b; ++k) {        
        chmin(dp[i + 1][j][k], dp[i][j][k]);
        if (j + a[i] <= sum_a && k + b[i] <= sum_b) chmin(dp[i + 1][j + a[i]][k + b[i]], dp[i][j][k] + c[i]);        
      }
    }
  }

  int res = INF;
  for (int i = ma, j = mb; i <= sum_a && j <= sum_b; i += ma, j += mb) chmin(res, dp[n][i][j]);
  cout << (res < INF ? res : -1) << endl;
  return 0;
}