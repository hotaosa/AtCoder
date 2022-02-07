#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr long long INF = 1LL << 60;

long long dist_calc(const vector<long long> &s, const vector<long long> &t, long long x, int west_s, int west_t) {
  long long ret = 0;
  auto p = lower_bound(s.begin(), s.end(), x);
  if (west_s) {
    if (p == s.begin()) return INF;        
    else --p;
  } else if (p == s.end()) return INF;
  long long cur = *p;
  ret += abs(x - cur);  
  p = lower_bound(t.begin(), t.end(), *p);
  if (west_t) {
    if (p == t.begin()) return INF;
    else --p;
  } else if (p == t.end()) return INF;
  ret += abs(*p - cur);
  return ret;
}

int main() {
  int a, b, q;
  cin >> a >> b >> q;
  vector<long long> s(a), t(b);
  for (auto &p : s) cin >> p;
  for (auto &p : t) cin >> p;
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());  
  
  while (q--) {
    long long x;
    cin >> x;
    long long res = INF;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        res = min(res, dist_calc(s, t, x, i, j));
        res = min(res, dist_calc(t, s, x, i, j));
      }
    }
    cout << res << endl;
  }
  return 0;
}
