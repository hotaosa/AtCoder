#include <bits/stdc++.h>

struct UnionFind {
  std::vector<int> par, siz;
  UnionFind(int n) : par(n, -1), siz(n, 1) {}
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
  int h, w, q;
  std::cin >> h >> w >> q;
  int n = h * w;  
  UnionFind uf(n);
  std::vector<bool> red(n, false);

  for (int i = 0; i < q; ++i) {
    int qu;
    std::cin >> qu;
    if (qu == 1) {
      int r, c;
      std::cin >> r >> c;
      --r; --c;
      int index = r * w + c;
      red[index] = true;
      if (index + w < n && red[index + w]) uf.unite(index, index + w);
      if (index - w >= 0 && red[index - w]) uf.unite(index, index - w);
      if (index % w != 0 && red[index - 1]) uf.unite(index, index - 1);
      if (index % w != w - 1 && red[index + 1]) uf.unite(index, index + 1);
    } else {
      int ra, ca, rb, cb;
      std::cin >> ra >> ca >> rb >> cb;
      --ra; --ca; --rb; --cb;
      int id1 = ra * w + ca;
      int id2 = rb * w + cb;
      if (red[id1] && red[id2] && uf.is_same(id1, id2)) std::cout << "Yes" << std::endl;
      else std::cout << "No" << std::endl;
    }
  }
  return 0;
}
