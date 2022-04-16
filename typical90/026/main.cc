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

  vector<vector<int> > group(2);
  vector<int> color(n, -1);

  auto dfs = [&](auto dfs, int v) -> void {
    int c = 0;
    for (int nv : graph[v]) if (color[nv] == 0) c = 1;
    color[v] = c;
    group[c].push_back(v);
    for (int nv : graph[v]) if (color[nv] == -1) dfs(dfs, nv);    
  };

  dfs(dfs, 0);

  int id = (int)group[1].size() >= n / 2;
  for (int i = 0; i < n / 2; ++i) cout << group[id][i] + 1 << " ";
  cout << endl;  
  return 0;
}
