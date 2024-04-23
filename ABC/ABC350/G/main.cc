#include <iostream>
#include <vector>
//
#include <atcoder/dsu>

using namespace std;
using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  atcoder::dsu uf(n);

  const ll mod = 998244353LL;
  vector<int> par(n, -1);

  auto Reroot = [&](auto Reroot, int v, int p = -1) -> void {
    if (par[v] != -1) {
      Reroot(Reroot, par[v], v);
    }
    par[v] = p;
  };

  auto Merge = [&](int u, int v) -> void {
    if (uf.size(u) < uf.size(v)) {
      swap(u, v);
    }
    uf.merge(u, v);
    Reroot(Reroot, v);
    par[v] = u;
  };

  auto Query = [&](int u, int v) -> int {
    int pu = par[u];
    int pv = par[v];
    int ppu = pu != -1 ? par[pu] : -1;
    int ppv = pv != -1 ? par[pv] : -1;
    if (ppu == v) return pu;
    if (ppv == u) return pv;
    if (pu == pv) return pu;
    return -1;
  };

  int x = 0;
  while (q--) {
    ll a, b, c;
    cin >> a >> b >> c;
    int t = a * (1 + x) % mod % 2;
    int u = b * (1 + x) % mod % n;
    int v = c * (1 + x) % mod % n;
    if (t) {
      x = Query(u, v) + 1;
      cout << x << endl;
    } else {
      Merge(u, v);
    }
  }

  return 0;
}