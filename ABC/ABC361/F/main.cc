#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

constexpr ll INF = 1LL << 60;

ll PowSafe(ll x, int n) {
  ll ret = 1;
  while (n--) {
    if ((ld)ret * x >= INF) return INF;
    ret *= x;
  }
  return ret;
}

ll Bound(int k, ll n) {
  ll l = 1, r = n;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    (PowSafe(m, k) <= n ? l : r) = m;
  }
  return l;
}

vector<pair<int, int>> PrimeFactorize(int x) {
  vector<pair<int, int>> ret;
  for (int p = 2; p * p <= x; ++p) {
    int cnt = 0;
    while (x % p == 0) {
      ++cnt;
      x /= p;
    }
    if (cnt) ret.emplace_back(p, cnt);
  }
  if (x > 1) ret.emplace_back(x, 1);
  return ret;
}

int main() {
  ll n;
  cin >> n;

  int siz = 1;
  while ((1LL << siz) <= n) ++siz;

  ll res = 1;
  for (int k = 2; k < siz; ++k) {
    auto pf = PrimeFactorize(k);
    bool valid = true;
    for (auto [p, c] : pf) valid &= (c == 1);
    if (!valid) continue;

    ll add = Bound(k, n) - 1;
    ll sign = size(pf) & 1 ? 1 : -1;
    res += add * sign;
  }

  cout << res << endl;
  return 0;
}