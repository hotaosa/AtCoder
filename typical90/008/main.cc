#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  string s;
  cin >> n >> s;

  string str = "atcoder";

  vector<vector<mint> > dp(n + 1, vector<mint>(str.size() + 1, 0));
  dp[0][0] = 1;  

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (int)str.size() + 1; ++j) dp[i + 1][j] = dp[i][j];
    for (int j = 0; j < (int)str.size(); ++j) if (s[i] == str[j]) dp[i + 1][j + 1] += dp[i][j];
  }

  cout << dp[n].back().val() << endl;
  return 0;
}
