#include <iostream>
#include <map>
#include <set>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

int Op(int a, int b) { return a + b; }
int E() { return 0; }
using Segtree = atcoder::segtree<int, Op, E>;

int main() {
  int q;
  ll k;
  cin >> q >> k;

  vector<int> t(q);
  vector<ll> x(q);
  for (int i = 0; i < q; ++i) {
    cin >> t[i] >> x[i];
  }

  auto m = *max_element(begin(x), end(x)) + k + 1;
  map<ll, int> mp = {{-k, 0}, {m, 0}};
  for (auto &y : x) {
    mp[y] = 0;
  }
  int siz = 0;
  for (auto &[k, v] : mp) {
    v = siz++;
  }

  set<ll> s1 = {-k, m};
  set<int> s2 = {0};
  Segtree seg(siz);

  auto Query1 = [&](ll x) -> void {
    auto it = s1.find(x);
    if (it == end(s1)) {
      it = s1.insert(x).first;
      seg.set(mp[x], 1);
      if (x - *prev(it) <= k) {
        s2.erase(mp[*prev(it)]);
      }
      if (*next(it) - x > k) {
        s2.insert(mp[x]);
      }
    } else {
      seg.set(mp[x], 0);
      s2.erase(mp[x]);
      if (*next(it) - *prev(it) > k) {
        s2.insert(mp[*prev(it)]);
      }
      s1.erase(it);
    }
  };

  auto Query2 = [&](ll x) -> int {
    auto it = s2.lower_bound(mp[x]);
    int l = *prev(it);
    return seg.prod(l + 1, *it + 1);
  };

  for (int i = 0; i < q; ++i) {
    if (t[i] == 1) {
      Query1(x[i]);
    } else {
      cout << Query2(x[i]) << endl;
    }
  }

  return 0;
}