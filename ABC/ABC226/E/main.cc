#include <iostream>
#include <vector>

struct UnionFind {
  int n;
  std::vector<int> par, v, e;
  UnionFind(int n_) : n(n_), par(n_, -1), v(n_, 1), e(n_, 0) { }
  int root(int i) {
    if (par[i] == -1) return i;
    else return par[i] = root(par[i]);
  }
  void unite(int i, int j) {
    i = root(i);
    j = root(j);
    if (i != j) {
      if (v[i] < v[j]) std::swap(i, j);
      par[j] = i;
      v[i] += v[j];
      e[i] += e[j] + 1;
    } else {
      ++e[i];
    }
  }
  int get_v(int i) { return v[root(i)]; }
  int get_e(int i) { return e[root(i)]; }
};

int main() {
  constexpr long long MOD = 998244353LL;
  int n, m;
  std::cin >> n >> m;
  UnionFind uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    uf.unite(--u, --v);
  }

  long long res = 1LL;
  for (int i = 0; i < n; ++i) {
    if (uf.root(i) == i) {
      res = res * (uf.get_v(i) == uf.get_e(i) ? 2LL : 0LL) % MOD;
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
