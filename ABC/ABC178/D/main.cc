#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int s;
  cin >> s;

  int siz = s / 3 + 1;
  vector<vector<mint> > dp(siz + 1, vector<mint>(s + 1, 0));
  dp[0][0] = 1;

  for (int i = 0; i < siz; ++i) {
    for (int j = 0; j <= s; ++j) {
      for (int k = 3; j + k <= s; ++k) {
        dp[i + 1][j + k] += dp[i][j];
      }
    }
  }

  mint res = 0;
  for (auto d : dp) res += d[s];
  cout << res.val() << endl;  
  return 0;
}
