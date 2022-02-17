#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}

int main() {
  int n, t;
  cin >> n >> t;
  vector<pair<int, int> > vp(n);
  for (int i = 0; i < n; ++i) cin >> vp[i].first >> vp[i].second;
  sort(vp.begin(), vp.end());  

  atcoder::segtree<int, op, e> seg(t + 3000);
  for (int i = 0; i < n; ++i) {
    for (int j = t - 1; j >= 0; --j) {
      int a = vp[i].first, b = vp[i].second;
      seg.set(j + a, max(seg.get(j + a), seg.prod(0, j + 1) + b));
    }
  }
  cout << seg.all_prod() << endl;
  return 0;
}
