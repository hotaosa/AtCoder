#include <iostream>
#include <vector>

struct UnionFind {
  std::vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) { }
  int root(int x) {
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }
  bool is_same(int x, int y) { return root(x) == root(y); }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) std::swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }
  int size(int x) { return siz[root(x)]; }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> p(n);
  for (int i = 0; i < n; ++i) { std::cin >> p[i]; --p[i]; }
  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int x, y;
    std::cin >> x >> y;
    --x; --y;
    uf.unite(x, y);
  }

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (uf.is_same(i, p[i])) ++res;
  }
  std::cout << res << std::endl;
  return 0;  
}
