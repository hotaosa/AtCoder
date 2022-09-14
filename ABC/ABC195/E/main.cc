#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  string s, x;
  cin >> n >> s >> x;

  vector<int> dp(n + 1, 0);
  dp[n] = 1;

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 7; ++j) {
      int nx1 = j * 10 % 7;
      int nx2 = (j * 10 + (s[i] - '0')) % 7;
      if (x[i] == 'T') {
        if (dp[i + 1] & (1 << nx1) || dp[i + 1] & (1 << nx2)) dp[i] |= (1 << j);
      } else {
        if (dp[i + 1] & (1 << nx1) && dp[i + 1] & (1 << nx2)) dp[i] |= (1 << j);
      }      
    }
  }

  cout << (dp[0] & 1 ? "Takahashi" : "Aoki") << endl;  
  return 0;
}
