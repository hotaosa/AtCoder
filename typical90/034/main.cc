#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  int siz = vcomp(a);

  int res = 0, cur = 0, l = -1;
  vector<int> cnt(siz, 0);  
  for (int r = 0; r < n; ++r) {
    if (++cnt[a[r]] == 1) ++cur;
    while (cur > k) {
      if (--cnt[a[++l]] == 0) --cur;
    }
    res = max(res, r - l);
  }

  cout << res << endl;  
  return 0;
}
