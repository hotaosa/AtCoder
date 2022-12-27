#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int> > a(h, vector<int>(w));
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      cin >> a[r][c];
    }
  }

  vector<vector<bool> > isolated(h, vector<bool>(w, true));
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w - 1; ++c) {
      if (a[r][c] == a[r][c + 1]) {
        isolated[r][c] = isolated[r][c + 1] = false;
      }
    }
  }

  vector<tuple<int, int, int> > rev;
  for (int i = 0; i < 8; ++i) {
    int rev0 = i & 1;
    int rev1 = (i >> 1) & 1;
    int rev2 = (i >> 2) & 1;
    rev.emplace_back(rev0, rev1, rev2);
  }
  
  vector<vector<vector<int> > > dp(h, vector<vector<int> > (2, vector<int>(2, INF)));
  dp[0][0][0] = 0;
  dp[0][0][1] = 1;

  for (int r = 1; r < h; ++r) {
    for (auto [rev0, rev1, rev2]: rev) {
      if (dp[r - 1][rev2][rev1] == INF) continue;
      bool possible = true;
      for (int c = 0; c < w; ++c) {
        if (!isolated[r - 1][c]) continue;
        bool ok = false;
        if (r > 1 && (a[r - 1][c] ^ rev1) == (a[r - 2][c] ^ rev2)) ok = true;
        if ((a[r - 1][c] ^ rev1) == (a[r][c] ^ rev0)) ok = true;
        possible &= ok;
      }
      if (possible) chmin(dp[r][rev1][rev0], dp[r - 1][rev2][rev1] + rev0);
    }
  }

  int res = INF;
  for (auto [rev0, rev1, rev2] : rev) {
    if (dp[h - 1][rev1][rev0] == INF) continue;
    bool possible = true;
    for (int c = 0; c < w; ++c) {
      if (!isolated[h - 1][c]) continue;
      possible &= (a[h - 1][c] ^ rev0) == (a[h - 2][c] ^ rev1);
    }
    if (possible) chmin(res, dp[h - 1][rev1][rev0]);
  }

  cout << (res < INF ? res : -1) << endl;  
  return 0;
}
