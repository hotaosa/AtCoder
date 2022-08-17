#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

constexpr long long INF = 1LL << 60;

string solve(long long x, long long y, long long p, long long q) {
  long long res = INF;
  for (long long a = x; a < x + y; ++a) {
    for (long long b = p; b < p + q; ++b) {
      auto r = atcoder::crt({a, b}, {2 * (x + y), p + q});
      if (r.second > 0) res = min(res, r.first);      
    }
  }
  return (res == INF ? "infinity" : to_string(res));
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y, p, q;
    cin >> x >> y >> p >> q;
    cout << solve(x, y, p, q) << endl;
  }  
  return 0;
}
