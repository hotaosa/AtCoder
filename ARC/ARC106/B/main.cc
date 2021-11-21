#include <bits/stdc++.h>
#include <atcoder/all>

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
    int n, m;
    std::cin >> n >> m;

    std::vector<long long> a(n, 0);
    std::vector<long long> b(n, 0);
    for (auto &p : a) std::cin >> p;
    for (auto &p : b) std::cin >> p;


    UnionFind uf(n);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        uf.unite(--u, --v);
    }

    std::map<int, std::pair<long long, long long> > ma;
    for (int i = 0; i < n; ++i) {
        ma[uf.root(i)].first += a[i];
        ma[uf.root(i)].second += b[i];
    }

    bool possible = true;
    for (auto &p : ma) if (p.second.first != p.second.second) possible = false;

    std::cout << (possible ? "Yes" : "No" ) << std::endl;
    return 0;
}
