#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int mex(set<int> se) {
  int cur = 0;
  while (true) {
    if (!se.count(cur)) return cur;
    else ++cur;
  }
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;

  int mx = 0;
  vector<int> a(n);  
  for (auto &p : a) { cin >> p; mx = max(mx, p); }  

  vector<int> grundy(mx + 1, -1);
  for (int i = 0; i < x; ++i) grundy[i] = 0;
  for (int i = x; i <= mx; ++i) {
    set<int> se;
    se.insert(grundy[i - x]);
    if (i >= y) se.insert(grundy[i - y]);
    grundy[i] = mex(se);
  }

  int res = 0;
  for (int i = 0; i < n; ++i) res ^= grundy[a[i]];
  cout << (res ? "First" : "Second") << endl;  
  return 0;
}
