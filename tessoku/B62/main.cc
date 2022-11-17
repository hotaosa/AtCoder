#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  vector<bool> used(n, false);
  vector<int> res;  
  auto dfs = [&](auto dfs, int v) -> bool {
    used[v] = true;
    res.push_back(v + 1);
    if (v == n - 1) return true;
    for (int nv : graph[v]) {
      if (used[nv]) continue;
      if (dfs(dfs, nv)) return true;
    }
    res.pop_back();
    return false;
  };

  dfs(dfs, 0);
  for (auto r : res) cout << r << " ";
  cout << endl;  
  return 0;
}
