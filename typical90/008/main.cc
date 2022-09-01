#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  string s;
  cin >> n >> s;

  map<char, int> mp = {{'a', 1}, {'t', 2}, {'c', 3}, {'o', 4}, {'d', 5}, {'e', 6}, {'r', 7}};
  vector<vector<mint> > dp(n + 1, vector<mint>(8, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= 7; ++j) dp[i + 1][j] = dp[i][j];
    if (mp[s[i]] > 0) dp[i + 1][mp[s[i]]] += dp[i][mp[s[i]] - 1];
  }

  cout << dp[n][7].val() << endl;  
  return 0;
}
