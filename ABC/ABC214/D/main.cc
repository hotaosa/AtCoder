#include <iostream>
#include <vector>
#include <algorithm>

struct UnionFind {
  std::vector<int> par, siz;
  UnionFind(int n_) : par(n_, -1), siz(n_, 1) { }
  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) std::swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }
  int size(int x) { return siz[root(x)]; }
};

struct Edge {
  int u, v;
  long long w;
  Edge(int u_, int v_, long long w_) : u(u_), v(v_), w(w_) { }
  bool operator<(const Edge &another) const {
    return w < another.w;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<Edge> ve;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    long long w;
    std::cin >> u >> v >> w;
    ve.push_back(Edge(--u, --v, w));
  }

  std::sort(ve.begin(), ve.end());
  UnionFind uf(n);
  long long res = 0LL;
  for (int i = 0; i < n - 1; ++i) {
    int u = ve[i].u;
    int v = ve[i].v;
    long long w = ve[i].w;
    res += w * uf.size(u) * uf.size(v);
    uf.unite(u, v);
  }

  std::cout << res << std::endl;
  return 0;
}
