#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int u, v, c;
  Edge(int u, int v, int c) : u(u), v(v), c(c) { }
  bool operator<(const Edge &rhs) const { return c < rhs.c; }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> ve;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    ve.emplace_back(--a, --b, c);
  }

  sort(ve.rbegin(), ve.rend());
  atcoder::dsu uf(n);
  int res = 0;
  for (int i = 0; i < m; ++i) {
    if (!uf.same(ve[i].u, ve[i].v)) {
      res += ve[i].c;
      uf.merge(ve[i].u, ve[i].v);
    }
  }

  cout << res << endl;

  
  return 0;
}
