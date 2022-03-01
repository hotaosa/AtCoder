#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, w;  
  cin >> n >> w;  
  vector<int> we(n), v(n);  
  for (int i = 0; i < n; ++i) cin >> we[i] >> v[i];
  int w0 = we[0];
  int sum = 0;
  for (int i = n - 1; i >= 0; --i) { we[i] -= we[0]; sum += we[i]; }

  vector<vector<vector<int> > > dp(n + 1, vector<vector<int> > (sum + 1, vector<int>(n + 1, 0)));
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= sum; ++j) {      
      for (int k = 0; k <= i; ++k) {        
        chmax(dp[i + 1][j][k], dp[i][j][k]);
        if (j + we[i] > sum) continue;
        chmax(dp[i + 1][j + we[i]][k + 1], dp[i][j][k] + v[i]);
        if ((long long)w0 * (k + 1) + j + we[i] <= w) chmax(res, dp[i][j][k] + v[i]);
      }
    }
  }
  cout << res << endl;
  return 0;
}
