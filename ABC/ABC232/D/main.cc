#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr int INF = 1 << 30;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int h, w;
  cin >> h >> w;

  vector<vector<bool> > is_wall(h, vector<bool>(w, false));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) if (s[j] == '#') is_wall[i][j] = true;
  }

  int res = 1;
  vector<vector<int> > dp(h, vector<int>(w, -INF));
  dp[0][0] = 1;
  int dr[] = {1, 0}, dc[] = {0, 1};
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      for (int i = 0; i < 2; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr < h && nc < w && !is_wall[nr][nc]) {
          if (chmax(dp[nr][nc], dp[r][c] + 1)) chmax(res, dp[nr][nc]);
        }
      }
    }
  }

  cout << res << endl;
  return 0;
}
