#include <iostream>
#include <vector>
#include <atcoder/lazysegtree>
#include <atcoder/string>

using namespace std;
using S = int;
using F = int;

const int INF = 1 << 30;

S op(S l, S r) { return min(l, r); }
S e() { return INF; }
S mapping(F f, S x) { return min(f, x); }
F composition(F f, F g) { return min(f, g); }
F id() { return INF; }

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();

  string st = s + '.' + t;
  auto z_st = atcoder::z_algorithm(st);

  vector<int> z(m);
  for (int i = 0; i < m; ++i) z[i] = z_st[i + n + 1];

  vector<int> dp(m + 1, INF);
  dp[0] = 0;  

  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(m + 1);
  seg.set(0, 0);

  for (int i = 0; i < m; ++i) {
    if (z[i] == 0) continue;
    int j = min(i + z[i], m);    
    int cur = seg.get(i);
    seg.apply(i + 1, j + 1, cur + 1);
  }

  int res = seg.get(m);
  cout << (res < INF ? res : -1) << endl;
  return 0;
}