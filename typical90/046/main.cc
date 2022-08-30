#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(3, vector<int>(n));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
      a[i][j] %= 46;
    }
  }  

  vector<vector<long long> > dp(4, vector<long long>(46, 0));
  dp[0][0] = 1;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 46; ++j) {
      for (int k = 0; k < n; ++k) {
        dp[i + 1][(j + a[i][k]) % 46] += dp[i][j];
      }
    }
  }  

  cout << dp[3][0] << endl;  
  return 0;
}
