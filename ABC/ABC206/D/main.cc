#include <iostream>
#include <vector>

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
    siz[x] += siz[y];
    return true;
  }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int ma = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ma = std::max(ma, a[i]);
  }
  UnionFind uf(++ma);

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (uf.unite(a[i], a[n - 1 - i])) ++res;
  }

  std::cout << res << std::endl;
  return 0;
}
