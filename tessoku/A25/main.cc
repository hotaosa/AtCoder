#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<bool> > is_wall(h, vector<bool>(w));
  for (int i = 0; i < h; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < w; ++j) is_wall[i][j] = s[j] == '#';
  }

  vector<vector<long long> > dp(h, vector<long long>(w, 0));
  dp[0][0] = 1;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (i < h - 1 && !is_wall[i + 1][j]) dp[i + 1][j] += dp[i][j];
      if (j < w - 1 && !is_wall[i][j + 1]) dp[i][j + 1] += dp[i][j];
    }
  }

  cout << dp.back().back() << endl;  
  return 0;
}
