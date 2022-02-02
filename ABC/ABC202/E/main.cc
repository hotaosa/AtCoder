#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > graph(n), list(n);
  vector<int> in(n, -1), out(n, -1), depth(n, -1);
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    graph[--p].push_back(i);
  }

  int cnt = 0;  
  depth[0] = 0;

  auto dfs = [&](auto dfs, int v) -> void {
    in[v] = cnt++;
    list[depth[v]].push_back(in[v]);
    for (int nv : graph[v]) {
      depth[nv] = depth[v] + 1;
      dfs(dfs, nv);
    }
    out[v] = cnt++;
  };

  dfs(dfs, 0);

  int q;
  cin >> q;
  while (q--) {
    int u, d;
    cin >> u >> d;
    --u;
    cout << lower_bound(list[d].begin(), list[d].end(), out[u]) - lower_bound(list[d].begin(), list[d].end(), in[u]) << endl;
  }
  return 0;
}
