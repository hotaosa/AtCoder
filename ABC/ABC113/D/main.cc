#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int h, w, k;
  cin >> h >> w >> k;

  auto valid = [&](int bit) -> bool {
    for (int i = 0; i < w - 1; ++i) {
      if (bit & (1 << i)) {
        if (bit & (1 << (i + 1))) return false;
      }
    }
    return true;
  };

  vector<vector<mint> > dp(h + 1, vector<mint>(w, 0));
  dp[0][0] = 1;

  for (int i = 0; i < h; ++i) {
    for (int bit = 0; bit < (1 << (w - 1)); ++bit) {
      if (!valid(bit)) continue;
      for (int j = 0; j < w; ++j) {        
        if (j < w - 1 && bit & (1 << j)) dp[i + 1][j + 1] += dp[i][j];
        else if (j > 0 && bit & (1 << (j - 1))) dp[i + 1][j - 1] += dp[i][j];
        else dp[i + 1][j] += dp[i][j];
      }
    }
  }

  cout << dp[h][--k].val() << endl;
  return 0;
}
