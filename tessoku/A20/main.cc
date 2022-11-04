#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int lcs(const string &a, const string &b) {
  vector<vector<int> > dp(a.size() + 1, vector<int>(b.size() + 1, 0));
  for (int i = 0; i < (int)a.size(); ++i) {
    for (int j = 0; j < (int)b.size(); ++j) {
      if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
      else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
    }
  }
  return dp[a.size()][b.size()];
}

int main() {
  string s, t;
  cin >> s >> t;
  cout << lcs(s, t) << endl;  
  return 0;
}
