#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> h(n), w(m);
  for (auto &p : h) cin >> p;
  for (auto &p : w) cin >> p;
  sort(h.begin(), h.end());
  sort(w.begin(), w.end());

  vector<long long> d_l(n, 0), d_r(n, 0);
  for (int i = 1; i < n - 1; i += 2) d_l[i + 1] = h[i] - h[i - 1];
  for (int i = n - 2; i > 0; i -= 2) d_r[i - 1] = h[i + 1] - h[i];
  for (int i = 1; i < n; ++i) d_l[i] += d_l[i - 1];
  for (int i = n - 2; i >= 0; --i) d_r[i] += d_r[i + 1];  

  long long res = 1LL << 30;
  for (int i = 0; i < n; ++i) {
    long long cur = d_l[i] + d_r[i];
    if (i & 1) cur += h[i + 1] - h[i - 1];

    long long add = 1LL << 30;
    auto p = lower_bound(w.begin(), w.end(), h[i]);
    if (p != w.end()) add = min(add, *p - h[i]);
    if (p != w.begin()) add = min(add, h[i] - *(--p));
    cur += add;
    res = min(res, cur);
  }

  cout << res << endl;  
  return 0;
}
