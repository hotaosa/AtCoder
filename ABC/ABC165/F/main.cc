#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int vcomp(vector<int> &v) {
  map<int, int> mem;
  for (auto p : v) mem[p] = 0;
  int sz= 0;
  for (auto &p : mem) p.second = sz++;
  for (auto &p : v) p = mem[p];
  return sz;
}

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &p : a) cin >> p;
  int sz = vcomp(a);
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  atcoder::segtree<int, op, e> seg(sz);
  vector<int> res(n, -1);
  res[0] = 1;  

  auto dfs = [&](auto dfs, int v, int par) -> void {    
    res[v] = max(seg.prod(0, a[v]) + 1, seg.prod(a[v], sz));
    int before = seg.get(a[v]);
    seg.set(a[v], seg.prod(0, a[v]) + 1);    
    for (int nv : graph[v]) {
      if (nv == par) continue;
      dfs(dfs, nv, v);
    }
    seg.set(a[v], before);
  };

  dfs(dfs, 0, -1);
  for (auto &p : res) cout << p << endl;
  return 0;
}
