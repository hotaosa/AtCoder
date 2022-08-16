#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

int digit(int x) {
  int res = 0;
  while (x) {
    ++res;
    x /= 10;
  }
  return res;
}

int main() {
  int n, p;
  cin >> n >> p;  

  mint::set_mod(p);
  vector<vector<mint> > dp(n + 1, vector<mint>(n));
  vector<vector<mint> > ds(n + 1, vector<mint>(n));
  for (int i = 1; i <= n; ++i) dp[i][digit(i) + 1] = 26;

  const int ten[] = {0, 0, 1, 10, 100, 1000, 10000};

  for (int i = 1; i <= n; ++i) {    
    for (int j = 1; j < n; ++j) {
      for (int k = 2; k <= min(5, j); ++k) {
        int lb = ten[k], ub = min(ten[k + 1], i);
        if (lb >= ub) continue;
        dp[i][j] += (ds[i - lb][j - k] - ds[i - ub][j - k]) * 25;        
      }
      ds[i][j] = ds[i - 1][j] + dp[i][j];
    }
  }    

  mint res = 0;
  for (auto r : dp[n]) res += r;
  cout << res.val() << endl;
  return 0;
}