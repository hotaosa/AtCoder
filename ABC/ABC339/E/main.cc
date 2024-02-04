#include <algorithm>
#include <iostream>
#include <utility>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

ll op(ll a, ll b) { return max(a, b); }
ll e() { return 0; }
using Segtree = atcoder::segtree<ll, op, e>;

int main() {
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto &e : a) cin >> e;

  int siz = *max_element(a.begin(), a.end()) + 1;
  Segtree seg(siz);

  for (int i = 0; i < n; ++i) {
    int l = max(0, a[i] - d);
    int r = min(siz, a[i] + d + 1);
    auto prod = seg.prod(l, r);
    seg.set(a[i], prod + 1);
  }

  cout << seg.all_prod() << endl;
  return 0;
}