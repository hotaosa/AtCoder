#include <iostream>
#include <vector>

struct UnionFind {
  int n;
  std::vector<int> par, siz;
  UnionFind(int n_) : n(n_), par(n_, -1), siz(n_, 1) { }
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
};

int main() {
  int n, m;
  std::cin >> n >> m;

  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    uf.unite(--x, --y);
  }

  int res = 0;
  for (int i = 0; i < n; ++i) if (uf.root(i) == i) ++res;
  std::cout << res << std::endl;
  return 0;
}
