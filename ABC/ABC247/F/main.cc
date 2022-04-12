#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

mint func(int n, int f) {
  vector<vector<mint> > dp(n, vector<mint>(2));
  dp[0][f] = 1;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = dp[i - 1][1];
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1];    
  }
  mint res = dp[n - 1][1];
  if (f == 1) res += dp[n - 1][0];
  return res;
}

int main() {    
  int n;
  cin >> n;  
  vector<int> p(n), q(n);
  for (auto &pp : p) { cin >> pp; --pp; }
  for (auto &pp : q) { cin >> pp; --pp; }

  atcoder::dsu uf(n);
  for (int i = 0; i < n; ++i) uf.merge(p[i], q[i]);

  mint res = 1;
  for (int i = 0; i < n; ++i) if (uf.leader(i) == i) res *= func(uf.size(i), 0) + func(uf.size(i), 1);
  cout << res.val() << endl;    
  return 0;
}
