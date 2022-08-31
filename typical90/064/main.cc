#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;
  for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
  a[0] = 0;

  long long res = 0;
  for (int i = 1; i < n; ++i) res += abs(a[i]);

  while (q--) {
    int l, r;
    long long v;
    cin >> l >> r >> v;
    --l;
    if (l > 0) {
      res -= abs(a[l]);
      a[l] += v;
      res += abs(a[l]);
    }
    if (r < n) {
      res -= abs(a[r]);
      a[r] -= v;
      res += abs(a[r]);
    }
    cout << res << endl;
  }  
  return 0;
}
