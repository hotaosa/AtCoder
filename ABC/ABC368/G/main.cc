#include <iostream>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

ll Add(ll a, ll b) { return a + b; }
ll Max(ll a, ll b) { return max(a, b); }
ll E() { return 0LL; }
bool LessThanTwo(ll x) { return x <= 1; }

using RangeSum = atcoder::segtree<ll, Add, E>;
using RangeMax = atcoder::segtree<ll, Max, E>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  for (auto &e : a) cin >> e;
  for (auto &e : b) cin >> e;

  RangeSum seg_a(a);
  RangeMax seg_b(b);

  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i;
      ll x;
      cin >> i >> x;
      seg_a.set(--i, x);
    } else if (t == 2) {
      int i;
      ll x;
      cin >> i >> x;
      seg_b.set(--i, x);
    } else {
      int l, r;
      cin >> l >> r;
      ll res = seg_a.get(l - 1);
      while (l < r) {
        int idx = min(r - 1, seg_b.max_right<LessThanTwo>(l));
        if (idx > l) {
          res += seg_a.prod(l, idx);
          l = idx;
        }
        res = max(res * seg_b.get(l), res + seg_a.get(l));
        ++l;
      }
      cout << res << endl;
    }
  }
  return 0;
}
