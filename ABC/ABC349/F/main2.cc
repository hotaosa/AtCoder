#include <iostream>
#include <map>
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

vector<pair<ll, int>> PrimeFactorize(ll num) {
  vector<pair<ll, int>> ret;
  for (ll x = 2; x * x <= num; ++x) {
    int cnt = 0;
    while (num % x == 0) {
      ++cnt;
      num /= x;
    }
    if (cnt) ret.emplace_back(x, cnt);
  }
  if (num) ret.emplace_back(num, 1);
  return ret;
}

ll Pow(ll x, int n) {
  ll ret = 1;
  while (n) {
    if (n & 1) {
      ret *= x;
    }
    n >>= 1;
    x *= x;
  }
  return ret;
}

int main() {
  int n;
  ll m;
  cin >> n >> m;

  if (m == 1LL) {
    mint res = 1;
    for (int i = 0; i < n; ++i) {
      ll x;
      cin >> x;
      if (x == 1) res *= 2;
    }
    cout << --res << endl;
    return 0;
  }

  auto vp = PrimeFactorize(m);
  const int cnt = size(vp);
  const int siz = 1 << cnt;

  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (m % x) continue;
    int b = 0;
    for (int j = 0; j < cnt; ++j) {
      auto [p, c] = vp[j];
      if (x % Pow(p, c) == 0) {
        b |= 1 << j;
      }
    }
    ++mp[b];
  }

  vector<mint> dp(siz);
  dp[0] = 1;
  for (auto [k, v] : mp) {
    auto mul = mint(2).pow(v) - 1;
    for (int b = siz - 1; b >= 0; --b) {
      dp[b | k] += dp[b] * mul;
    }
  }

  cout << dp.back() << endl;
  return 0;
}
