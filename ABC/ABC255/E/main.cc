#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> s(n - 1), x(m), a(n, 0);
  for (auto &p : s) cin >> p;
  for (auto &p : x) cin >> p;

  for (int i = 1; i < n; ++i) a[i] = s[i - 1] - a[i - 1];
  map<long long, int> mp;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      long long d = a[i] - x[j];
      if (i & 1) d *= -1;
      res = max(res, ++mp[d]);
    }
  }
  cout << res << endl;
  return 0;
}
