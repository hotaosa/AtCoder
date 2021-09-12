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
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) std::swap(x, y);
    par[y] = x;
    siz[x] += y;
    return true;
  }
};

struct Edge {
  int a, b;
  long long c;
  Edge(int a_, int b_, long long c_) : a(a_), b(b_), c(c_) { }
  bool operator<(const Edge &another) const {
    return c < another.c;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Edge> ve;
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    std::cin >> a >> b >> c;
    ve.push_back(Edge(--a, --b, c));
  }
  std::sort(ve.begin(), ve.end());

  UnionFind uf(n);
  long long res = 0LL;
  for (int i = 0; i < m; ++i) {
    if (ve[i].c < 0) {
      uf.unite(ve[i].a, ve[i].b);
    } else if (!uf.unite(ve[i].a, ve[i].b)) res += ve[i].c;
  }

  std::cout << res << std::endl;
  return 0;
}
