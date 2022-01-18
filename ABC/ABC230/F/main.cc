#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  a.pop_back();
  --n;

  vector<mint> dp(n + 1, 0);
  dp[0] = 1;
  map<long long, int> ma;
  
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = dp[i] * 2;
    if (ma.find(a[i]) != ma.end()) dp[i + 1] -= dp[ma[a[i]]];
    ma[a[i]] = i;
  }
  
  cout << dp[n].val() << endl;  
  return 0;
}
