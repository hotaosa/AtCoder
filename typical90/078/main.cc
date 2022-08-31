#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  int res = 0;
  for (int v = 0; v < n; ++v) {
    int cnt = 0;
    for (int nv : graph[v]) if (nv < v) ++cnt;
    if (cnt == 1) ++res;
  }

  cout << res << endl;  
  return 0;
}
