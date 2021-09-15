#include <iostream>
#include <vector>
#include <algorithm>

struct UnionFind {
  std::vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) { }
  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }
  bool is_same(int x, int y) { return root(x) == root(y); }
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
  int n, m;
  std::cin >> n >> m;
  ++n;

  UnionFind uf(n);
  std::vector<Edge> ve;
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long w;
    std::cin >> w >> u >> v;
    ve.push_back(Edge(--u, v, w));
  }
  std::sort(ve.begin(), ve.end());

  long long res = 0LL;
  for (int i = 0; i < m; ++i) {
    if (uf.unite(ve[i].u, ve[i].v)) res += ve[i].w;
  }

  std::cout << (uf.size(0) == n ? res : -1LL) << std::endl;
  return 0;  
}
