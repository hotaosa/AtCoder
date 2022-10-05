#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

  vector<vector<bool> > dp(n + 1, vector<bool>(s + 1, false));
  dp[0][0] = true;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < s; ++j) {
      if (!dp[i][j]) continue;
      if (j + a[i] <= s) dp[i + 1][j + a[i]] = true;
      if (j + b[i] <= s) dp[i + 1][j + b[i]] = true;
    }
  }

  if (!dp[n][s]) { cout << "No" << endl; return 0; }

  cout << "Yes" << endl;
  string res = "";
  int cur = s;
  for (int i = n - 1; i >= 0; --i) {
    if (cur >= a[i] && dp[i][cur - a[i]]) {
      res += 'H';
      cur -= a[i];
    } else {
      res += 'T';
      cur -= b[i];
    }    
  }
  reverse(res.begin(), res.end());
  cout << res << endl;  
  return 0;
}
