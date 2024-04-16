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
  vector<int> cnt(1 << (int)size(vp), 0);
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    if (m % x) continue;
    int b = 0;
    for (int j = 0; j < (int)size(vp); ++j) {
      auto [p, c] = vp[j];
      if (x % Pow(p, c) == 0) {
        b |= 1 << j;
      }
    }
    ++cnt[b];
  }

  for (int i = 0; i < (int)size(vp); ++i) {
    for (int j = 0; j < (1 << size(vp)); ++j) {
      if (!(j >> i & 1)) {
        cnt[j | (1 << i)] += cnt[j];
      }
    }
  }
  vector<mint> h(1 << size(vp));
  for (int i = 0; i < (1 << size(vp)); ++i) {
    h[i] = mint(2).pow(cnt[i]);
  }

  for (int i = 0; i < (int)size(vp); ++i) {
    for (int j = 0; j < (1 << size(vp)); ++j) {
      if (!(j >> i & 1)) {
        h[j | (1 << i)] -= h[j];
      }
    }
  }
  cout << h.back() << endl;
  return 0;
}
