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

  for (int i = 0; i < n; ++i) {
    sort(graph[i].begin(), graph[i].end());
    cout << graph[i].size() << " ";
    for (auto v : graph[i]) cout << v + 1 << " ";
    cout << endl;
  }
  
  return 0;
}
