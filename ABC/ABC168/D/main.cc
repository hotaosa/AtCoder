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

  vector<pair<int, int> > dist(n, {1 << 30, -1});
  dist[0] = {0, -1};
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv].second != -1) continue;
      dist[nv].first = dist[v].first;
      dist[nv].second = v;
      que.push(nv);
    }
  }

  cout << "Yes" << endl;
  for (int i = 1; i < n; ++i) {
    cout << dist[i].second + 1 << endl;
  }  
  return 0;
}
