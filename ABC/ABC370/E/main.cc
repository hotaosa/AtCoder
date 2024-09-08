#include <iostream>
#include <map>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using mint = atcoder::modint998244353;
using ll = long long;

int main() {
  int n;
  ll k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];

  map<ll, mint> mp;
  vector<mint> dp(n, 0);
  mint sum = 1;
  mp[0] = dp[0] = 1;

  for (int i = 0; i < n; ++i) {
    dp[i] = sum - mp[a[i] - k];
    mp[a[i]] += dp[i];
    sum += dp[i];
  }

  cout << dp.back().val() << endl;
  return 0;
}
