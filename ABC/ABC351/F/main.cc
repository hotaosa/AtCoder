#include <iostream>
#include <map>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;
using ll = long long;

pair<ll, int> Op(pair<ll, int> a, pair<ll, int> b) {
  ll x = a.first + b.first;
  int y = a.second + b.second;
  return make_pair(x, y);
}
pair<ll, int> E() { return {0, 0}; }
using Segtree = atcoder::segtree<pair<ll, int>, Op, E>;

template <class T>
int Compression(vector<T> &v) {
  map<T, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz = 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &e : a) cin >> e;
  auto b = a;
  int siz = Compression(b);

  Segtree seg(siz);
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    auto [sum, cnt] = seg.prod(0, b[i]);
    res += a[i] * cnt - sum;
    seg.set(b[i], Op(seg.get(b[i]), {a[i], 1}));
  }

  cout << res << endl;
  return 0;
}