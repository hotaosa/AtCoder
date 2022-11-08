#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int from, to, w;
  Edge(int from, int to, int w) : from(from), to(to), w(w) { }
  bool operator<(const Edge &rhs) const { return w < rhs.w; }
};

int kruskal(int siz, vector<Edge> &ve) {
  atcoder::dsu uf(siz);
  sort(ve.begin(), ve.end());
  int ret = 0;
  for (auto e : ve) {
    if (!uf.same(e.from, e.to)) {
    uf.merge(e.from, e.to);
    ret += e.w;
    }
  }
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> ve;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    ve.emplace_back(--u, --v, c);
  }

  cout << kruskal(n, ve) << endl;  
  return 0;
}
