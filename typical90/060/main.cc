#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;

  vector<int> lis;
  vector<int> cnt(n, 1);

  for (int i = 0; i < n; ++i) {
    auto p = lower_bound(lis.begin(), lis.end(), a[i]);
    cnt[i] += p - lis.begin();
    if (p == lis.end()) lis.push_back(a[i]);
    else *p = a[i];
  }

  lis.clear();
  int res = 0;
  for (int i = n - 1; i >= 0; --i) {
    auto p = lower_bound(lis.begin(), lis.end(), a[i]);
    cnt[i] += p - lis.begin();
    if (p == lis.end()) lis.push_back(a[i]);
    else *p = a[i];
    res = max(res, cnt[i]);
  }

  cout << res << endl;
  return 0;
}
