#include <iostream>
#include <vector>
//
#include <atcoder/modint>

using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) {
  long long in;
  is >> in;
  m = in;
  return is;
}
ostream &operator<<(ostream &os, const mint &m) {
  os << m.val();
  return os;
}

int Count(ll x, ll y) {
  int ret = 0;
  while (x % y == 0) {
    ++ret;
    x /= y;
  }
  return ret;
}

int main() {
  int n;
  ll m;
  cin >> n >> m;

  vector<ll> a;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (m % x == 0) {
      a.emplace_back(x);
    }
  }
  n = size(a);

  if (m == 1LL) {
    mint res = 1;
    for (auto x : a) {
      if (x == 1LL) {
        res *= 2;
      }
    }
    cout << --res << endl;
    return 0;
  }

  vector<pair<ll, int>> vp;
  for (ll x = 2; x * x <= m; ++x) {
    int cnt = 0;
    while (m % x == 0) {
      ++cnt;
      m /= x;
    }
    if (cnt) {
      vp.emplace_back(x, cnt);
    }
  }
  if (m > 1) {
    vp.emplace_back(m, 1);
  }

  const int cnt = size(vp);
  const int siz = 1 << cnt;

  vector<mint> dp(siz);
  dp[0] = 1;
  for (auto x : a) {
    int add_b = 0;
    for (int i = 0; i < cnt; ++i) {
      auto [p, c] = vp[i];
      if (Count(x, p) == c) {
        add_b |= 1 << i;
      }
    }
    for (int b = siz - 1; b >= 0; --b) {
      dp[b | add_b] += dp[b];
    }
  }

  cout << dp[siz - 1] << endl;
  return 0;
}
