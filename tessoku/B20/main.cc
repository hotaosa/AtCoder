#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  string s, t;
  cin >> s >> t;

  int ls = s.size(), lt = t.size();

  const int INF = 1 << 30;
  vector<vector<int> > dp(ls + 1, vector<int>(lt + 1, INF));
  for (int i = 0; i <= ls; ++i) dp[i][0] = i;
  for (int i = 0; i <= lt; ++i) dp[0][i] = i;

  for (int i = 0; i < ls; ++i) {
    for (int j = 0; j < lt; ++j) {
      chmin(dp[i + 1][j + 1], dp[i + 1][j] + 1);
      chmin(dp[i + 1][j + 1], dp[i][j + 1] + 1);
      chmin(dp[i + 1][j + 1], dp[i][j] + 1);
      if (s[i] == t[j]) chmin(dp[i + 1][j + 1], dp[i][j]);
    }
  }

  cout << dp[ls][lt] << endl;
  return 0;
}
