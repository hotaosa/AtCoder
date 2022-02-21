#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  constexpr int MAXK = 20;
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (auto &p : x) cin >> p;

  vector<vector<int> > graph(n), subtree(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }
  
  auto dfs = [&](auto dfs, int v, int p) -> void {
    subtree[v].push_back(x[v]);
    for (int nv : graph[v]) {
      if (nv == p) continue;
      dfs(dfs, nv, v);
      for (int add : subtree[nv]) subtree[v].push_back(add);
    }
    sort(subtree[v].begin(), subtree[v].end(), greater<>());
    if (subtree[v].size() > MAXK) subtree[v].erase(subtree[v].begin() + MAXK, subtree[v].end());
  };

  dfs(dfs, 0, -1);

  while (q--) {
    int v, k;
    cin >> v >> k;
    cout << subtree[--v][--k] << endl;
  }
  return 0;
}
