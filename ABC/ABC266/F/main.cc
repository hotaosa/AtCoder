#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > graph(n);
  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  set<int> se;
  vector<bool> used(n, false);
  vector<int> cur;  
  auto dfs = [&](auto dfs, int v, int p = -1) -> bool {
    if (used[v]) {
      int s = 0;
      while(cur[s] != v) ++s;
      for (; s < (int)cur.size(); ++s) se.insert(cur[s]);
      return true;
    }
    used[v] = true;
    cur.push_back(v);    
    for (int nv : graph[v]) {
      if (nv == p) continue;      
      if (dfs(dfs, nv, v)) return true;
    }
    used[v] = false;
    cur.pop_back();
    return false;
  };

  dfs(dfs, 0);

  atcoder::dsu uf(n);
  for (int v = 0; v < n; ++v) {
    for (int nv : graph[v]) {
      if (se.count(v) && se.count(nv)) continue;
      uf.merge(v, nv);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << (uf.same(--u, --v) ? "Yes" : "No" ) << endl;
  }  
  return 0;
}
