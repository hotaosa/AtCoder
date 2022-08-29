#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

pair<long long, long long> frac(long long u, long long l) {
  long long g = __gcd(u, l);
  u /= g;
  l /= g;
  if (l < 0) return {-u, -l};
  else return {u, l};
}

pair<long long, long long> rev(pair<long long, long long> p) {
  return frac(-p.second, p.first);
}

int main() {
  int n;
  cin >> n;

  long long cnt_a0 = 0, cnt_b0 = 0, cnt_ab0 = 0;
  map<pair<long long, long long>, long long> cnt_frac;

  for (int i = 0; i < n; ++i) {
    long long a, b;
    cin >> a >> b;
    if (a == 0 && b == 0) ++cnt_ab0;
    else if (a == 0) ++cnt_a0;
    else if (b == 0) ++cnt_b0;
    else ++cnt_frac[frac(a, b)];
  }

  mint res = mint(2).pow(cnt_a0) + mint(2).pow(cnt_b0) - 1;
  set<pair<long long, long long> > used;
  for (auto m : cnt_frac) {
    if (used.count(m.first)) continue;
    auto p = m.first;
    auto pp = rev(p);
    if (cnt_frac.count(pp)) {
      res *= mint(2).pow(cnt_frac[p]) + mint(2).pow(cnt_frac[pp]) - 1;
      used.insert(pp);
    } else {
      res *= mint(2).pow(cnt_frac[p]);
    }
  }
  res += cnt_ab0 - 1;
  cout << res.val() << endl;  
  return 0;
}
