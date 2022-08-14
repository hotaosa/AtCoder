#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr long long INF = 1LL << 60;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

long long solve(const vector<long long> &cost_r, const vector<long long> &cost_c, const vector<vector<int> > &grid) {
  int h = cost_r.size();
  int w = cost_c.size();
  vector<vector<vector<vector<long long> > > > dp(h, vector<vector<vector<long long> > >(w, vector<vector<long long> > (2, vector<long long>(2, INF))));
  if (grid[0][0] == 0) {
    dp[0][0][0][0] = 0;
    dp[0][0][1][1] = cost_r[0] + cost_c[0];
  } else {
    dp[0][0][1][0] = cost_r[0];
    dp[0][0][0][1] = cost_c[0];
  }
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i > 0) {
        if (grid[i][j] == 0) {
          chmin(dp[i][j][0][0], dp[i - 1][j][0][0]);
          chmin(dp[i][j][0][0], dp[i - 1][j][1][0]);
          chmin(dp[i][j][1][1], dp[i - 1][j][0][1] + cost_r[i]);
          chmin(dp[i][j][1][1], dp[i - 1][j][1][1] + cost_r[i]);
        } else {          
          chmin(dp[i][j][0][1], dp[i - 1][j][0][1]);
          chmin(dp[i][j][0][1], dp[i - 1][j][1][1]);
          chmin(dp[i][j][1][0], dp[i - 1][j][0][0] + cost_r[i]);
          chmin(dp[i][j][1][0], dp[i - 1][j][1][0] + cost_r[i]);
        }
      }
      if (j > 0) {
        if (grid[i][j] == 0) {
          chmin(dp[i][j][0][0], dp[i][j - 1][0][0]);
          chmin(dp[i][j][0][0], dp[i][j - 1][0][1]);
          chmin(dp[i][j][1][1], dp[i][j - 1][1][0] + cost_c[j]);
          chmin(dp[i][j][1][1], dp[i][j - 1][1][1] + cost_c[j]);
        } else {
          chmin(dp[i][j][0][1], dp[i][j - 1][0][0] + cost_c[j]);
          chmin(dp[i][j][0][1], dp[i][j - 1][0][1] + cost_c[j]);
          chmin(dp[i][j][1][0], dp[i][j - 1][1][0]);
          chmin(dp[i][j][1][0], dp[i][j - 1][1][1]);          
        }
      }
    }
  }
  long long res = INF;
  for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) chmin(res, dp[h - 1][w - 1][i][j]);
  return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<long long> cost_r(h), cost_c(w);
  for (int i = 0; i < h; ++i) cin >> cost_r[i];
  for (int i = 0; i < w; ++i) cin >> cost_c[i];
  vector<vector<int> > grid(h, vector<int>(w));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) grid[i][j] = s[j] - '0';
  }

  long long res = solve(cost_r, cost_c, grid);
  for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) grid[i][j] ^= 1;
  chmin(res, solve(cost_r, cost_c, grid));
  cout << res << endl;
  return 0;
}
