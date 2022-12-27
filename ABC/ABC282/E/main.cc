#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint;

struct Edge {
  int u, v;
  mint w;
  Edge(int u, int v, mint w) : u(u), v(v), w(w) { }
  bool operator<(const Edge &other) const {
    return w.val() < other.w.val();
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  mint::set_mod(m);

  vector<mint> a(n);
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    a[i] = ai;
  }

  vector<Edge> edges;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 1; j < n; ++j) {
      edges.emplace_back(i, j, a[i].pow(a[j].val()) + a[j].pow(a[i].val()));
    }
  }
  sort(edges.rbegin(), edges.rend());

  atcoder::dsu uf(n);
  long long res = 0;
  for (auto e : edges) {
    if (!uf.same(e.u, e.v)) {
      uf.merge(e.u, e.v);
      res += e.w.val();
    }
  }

  cout << res << endl;
  return 0;
}
