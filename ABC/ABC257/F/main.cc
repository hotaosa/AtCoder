#include <iostream>
#include <vector>
#include <queue>

using namespace std;
constexpr int INF = 1000000;

vector<int> bfs(const vector<vector<int> > &graph, int s) {
  int n = graph.size();
  vector<int> dist(n, INF);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nv : graph[v]) {
      if (dist[nv] == INF) {
        dist[nv] = dist[v] + 1;
        que.push(nv);
      }
    }
  }
  return dist;  
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int> > graph(n + 1);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }  

  auto dist_1 = bfs(graph, 1);
  auto dist_n = bfs(graph, n);
  
  for (int i = 1; i <= n; ++i) {
    int res = dist_1[n];
    res = min(res, dist_1[i] + dist_n[0]);
    res = min(res, dist_1[0] + dist_n[i]);
    cout << (res < INF ? res : -1) << " ";
  }
  cout << endl;
  return 0;
}