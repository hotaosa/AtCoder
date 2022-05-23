#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int> > diff(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      cin >> diff[i][j];
    }
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      int b;
      cin >> b;
      diff[i][j] = abs(diff[i][j] - b);
    }
  }

  const int SIZ = 80 * (h + w);
  vector<vector<vector<bool> > > dp(h, vector<vector<bool> > (w, vector<bool>(SIZ, false)));
  dp[0][0][diff[0][0]] = true;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (int k = 0; k < SIZ; ++k) {
        if (!dp[i][j][k]) continue;
        if (i < h - 1) {
          int nx1 = k + diff[i + 1][j];
          int nx2 = abs(k - diff[i + 1][j]);
          if (nx1 < SIZ) dp[i + 1][j][nx1] = true;
          if (nx2 < SIZ) dp[i + 1][j][nx2] = true;
        }
        if (j < w - 1) {
          int nx1 = k + diff[i][j + 1];
          int nx2 = abs(k - diff[i][j + 1]);
          if (nx1 < SIZ) dp[i][j + 1][nx1] = true;
          if (nx2 < SIZ) dp[i][j + 1][nx2] = true;
        }
      }
    }
  }

  int res = 1 << 30;
  for (int i = SIZ - 1; i >= 0; --i) if (dp[h - 1][w - 1][i]) res = i;
  cout << res << endl;
  return 0;
}
