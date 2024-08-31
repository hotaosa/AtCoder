#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
//
#include <atcoder/segtree>

using namespace std;

string PathString(pair<int, int> s, pair<int, int> g) {
  int dr = g.first - s.first, dc = g.second - s.second;
  assert(dr >= 0 && dc >= 0);
  return string(dr, 'D') + string(dc, 'R');
}

using S = pair<int, int>;
S Max(S a, S b) { return max(a, b); }
S e() { return S{0, -1}; }
using RangeMax = atcoder::segtree<pair<int, int>, Max, e>;

int main() {
  int h, w, n;
  cin >> h >> w >> n;

  vector<int> r(n), c(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i] >> c[i];
    --r[i];
    --c[i];
  }

  vector<int> order(n);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&r, &c](int i, int j) {
    return make_pair(c[i], r[i]) < make_pair(c[j], r[j]);
  });

  vector<int> prev_node(n, -1);
  RangeMax seg(h);
  for (int i : order) {
    auto [x, v] = seg.prod(0, r[i] + 1);
    prev_node[i] = v;
    seg.set(r[i], {x + 1, i});
  }

  auto [x, v] = seg.all_prod();
  string path = PathString({r[v], c[v]}, {h - 1, w - 1});
  while (prev_node[v] != -1) {
    path += PathString({r[prev_node[v]], c[prev_node[v]]}, {r[v], c[v]});
    v = prev_node[v];
  }
  path += PathString({0, 0}, {r[v], c[v]});
  reverse(begin(path), end(path));

  cout << x << endl << path << endl;
  return 0;
}
