#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<long long> > item(h, vector<long long>(w, 0));
  for (int i = 0; i < k; ++i) {
    int r, c, v;
    cin >> r >> c >> v;
    item[--r][--c] = v;
  }

  vector<vector<vector<long long> > > dp(h, vector<vector<long long> > (w, vector<long long>(4, 0)));
  dp[0][0][0] = 0;
  dp[0][0][1] = item[0][0];

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      for (int cnt = 0; cnt < 4; ++cnt) {
        if (i > 0) {
          chmax(dp[i][j][0], dp[i - 1][j][cnt]);
          chmax(dp[i][j][1], dp[i - 1][j][cnt] + item[i][j]);
        }
        if (j > 0) {
          chmax(dp[i][j][cnt], dp[i][j - 1][cnt]);
          if (cnt > 0) chmax(dp[i][j][cnt], dp[i][j - 1][cnt - 1] + item[i][j]);
        }        
      }
    }
  }

  long long res = 0;
  for (int i = 0; i < 4; ++i) chmax(res, dp[h - 1][w - 1][i]);
  cout << res << endl;
  return 0;
}
