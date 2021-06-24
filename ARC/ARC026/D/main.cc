#include <iostream>
#include <vector>
#include <tuple>
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
  bool is_same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return siz[root(x)]; }
};

struct Road {
  int a, b;
  double c, t;
  Road(int a_, int b_, double c_, double t_) : a(a_), b(b_), c(c_), t(t_) { }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Road> vr;
  for (int i = 0; i < m; ++i) {
    int a, b;
    double c, t;
    std::cin >> a >> b >> c >> t;
    vr.push_back(Road(a, b, c, t));    
  }

  auto can = [&](double k) -> bool {
    std::vector<std::tuple<double, int, int> > vt;
    for (int i = 0; i < m; ++i) {
      vt.push_back(std::make_tuple(vr[i].c - vr[i].t * k, vr[i].a, vr[i].b));
    }
    std::sort(vt.begin(), vt.end());
    UnionFind uf(n);
    double sum = 0.0;
    for (int i = 0; i < m; ++i) {
      double d = std::get<0>(vt[i]);
      int aa = std::get<1>(vt[i]);
      int bb = std::get<2>(vt[i]);
      if (d < 0.0 || !uf.is_same(aa, bb)) {
        sum += d;
        uf.unite(aa, bb);
      }
      if (sum > 0.0) return false;
      if (uf.size(0) == n) return true;
    }
    return false;
  };
  
  double l = 0.0, r = 1.0e+20;
  while (r - l > 1e-8) {
    double mid = (l + r) / 2.0;
    if (can(mid)) r = mid;
    else l = mid;
  }

  printf("%.5f\n", r);
  return 0;  
}
