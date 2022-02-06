#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<bool> > is_wall(h, vector<bool>(w));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_wall[i][j] = (s[j] == '#');
  }

  vector<vector<mint> > dp(h, vector<mint>(w, 0));
  dp[0][0] = 1;

  vector<vector<vector<mint> > > sum(h, vector<vector<mint> > (w, vector<mint>(3, 0)));
  sum[0][0][0] = sum[0][0][1] = sum[0][0][2] = 1;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (is_wall[i][j]) continue;
      if (i > 0) dp[i][j] += sum[i - 1][j][0];
      if (j > 0) dp[i][j] += sum[i][j - 1][1];
      if (i > 0 && j > 0) dp[i][j] += sum[i - 1][j - 1][2];
      sum[i][j][0] = sum[i][j][1] = sum[i][j][2] = dp[i][j];
      if (i > 0) sum[i][j][0] = sum[i - 1][j][0] + dp[i][j];
      if (j > 0) sum[i][j][1] = sum[i][j - 1][1] + dp[i][j];
      if (i > 0 && j > 0) sum[i][j][2] = sum[i - 1][j - 1][2] + dp[i][j];
    }
  }

  cout << dp[h - 1][w - 1].val() << endl;
  return 0;
}
