#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);    
  }

  vector<pair<int, int> > res(n);
  int cur = 1;

  auto dfs = [&](auto dfs, int v, int p) -> void {
    if (p != -1 && graph[v].size() == 1) {
      res[v] = make_pair(cur, cur);
      ++cur;
      return;
    }
    int mi = 1 << 30, ma = 0;
    for (int nv : graph[v]) {
      if (nv == p) continue;
      dfs(dfs, nv, v);
      mi = min(mi, res[nv].first);
      ma = max(ma, res[nv].second);
    }
    res[v] = make_pair(mi, ma);
  };

  dfs(dfs, 0, -1);
  for (auto &p : res) cout << p.first << " " << p.second << endl;
  return 0;
}
