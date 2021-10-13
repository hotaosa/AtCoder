#include <iostream>
#include <vector>

int h, w, q;

struct UnionFind {
  int n;
  std::vector<int> par, siz, color;
  UnionFind(int n_) : n(n_), par(n_, -1), siz(n_, 1), color(n_, -1) { }
  int root(int i) {
    if (par[i] == -1) return i;
    else return par[i] = root(par[i]);
  }
  bool is_same(int i, int j) {
    return root(i) == root(j);
  }
  bool unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i == j) return false;
    if (siz[i] < siz[j]) std::swap(i, j);
    par[j] = i;
    siz[i] += siz[j];
    return true;
  }
  void paint(int i) {
    color[i] = 1;
    std::vector<int> nx;
    if (i % w > 0) nx.push_back(i - 1);
    if (i % w < w - 1) nx.push_back(i + 1);
    if (i / w > 0) nx.push_back(i - w);
    if (i / w < h - 1) nx.push_back(i + w);
    for (int j : nx) if (color[j] == 1) unite(i, j);
  }
};

int main() {
  std::cin >> h >> w >> q;
  UnionFind uf(h * w);
  while (q--) {
    int qi;
    std::cin >> qi;
    if (qi == 1) {
      int r, c;
      std::cin >> r >> c;
      --r;
      --c;
      uf.paint(r * w + c);
    } else {
      int ra, ca, rb, cb;
      std::cin >> ra >> ca >> rb >> cb;
      --ra;
      --ca;
      --rb;
      --cb;
      int pa = ra * w + ca, pb = rb * w + cb;
      if (pa == pb) std::cout << (uf.color[pa] == 1 ? "Yes" : "No") << std::endl;
      else std::cout << (uf.is_same(pa, pb) ? "Yes" : "No") << std::endl;
    }
  }
  return 0;
}
