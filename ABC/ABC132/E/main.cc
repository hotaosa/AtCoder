#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);    
  }

  int s, t;
  cin >> s >> t;
  --s; --t;

  vector<vector<int> > dist(n, vector<int>(3, INF));
  dist[s][0] = 0;

  queue<pair<int, int> > que;
  que.emplace(s, 0);
  while (!que.empty()) {
    int v = que.front().first;
    int c = que.front().second;
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv][(c + 1) % 3] == INF) {
        dist[nv][(c + 1) % 3] = dist[v][c] + (c == 2 ? 1 : 0);
        que.emplace(nv, (c + 1) % 3);
      }
    }
  }

  cout << (dist[t][0] < INF ? dist[t][0] : -1) << endl;  
  return 0;
}
