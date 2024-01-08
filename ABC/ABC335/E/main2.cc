// UnionFind

#include <iostream>
#include <numeric>
#include <vector>

#include <atcoder/dsu>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), u(m), v(m);
  for (auto &e : a) cin >> e;

  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    if (a[--u[i]] == a[--v[i]]) uf.merge(u[i], v[i]);
  }

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int lu = uf.leader(u[i]), lv = uf.leader(v[i]);
    if (uf.same(lu, lv)) continue;
    if (a[lu] < a[lv]) {
      graph[lu].emplace_back(lv);
    } else {
      graph[lv].emplace_back(lu);
    }
  }

  vector<int> o(n);
  iota(o.begin(), o.end(), 0);
  sort(o.begin(), o.end(), [&](int i, int j) { return a[i] < a[j]; });

  vector<int> dp(n, 0);
  dp[uf.leader(0)] = 1;
  for (int v : o) {
    if (uf.leader(v) != v || dp[v] == 0) continue;
    for (int nv : graph[v]) {
      dp[nv] = max(dp[nv], dp[v] + (a[nv] > a[v]));
    }
  }
  cout << dp[uf.leader(n - 1)] << endl;

  return 0;
}