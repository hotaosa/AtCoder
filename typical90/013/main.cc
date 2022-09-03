#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int to, w;
  Edge(int to, int w) : to(to), w(w) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<int> dijcstra(const vector<vector<Edge> > &graph, int s) {
  int n = graph.size();
  vector<int> dist(n, 1 << 30);
  dist[s] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pque;
  pque.emplace(0, s);
  while (!pque.empty()) {
    int d = pque.top().first;
    int v = pque.top().second;
    pque.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v]) if (chmin(dist[e.to], d + e.w)) pque.emplace(dist[e.to], e.to);
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph[--u].emplace_back(--v, c);
    graph[v].emplace_back(u, c);
  }

  auto dist1 = dijcstra(graph, 0);
  auto dist2 = dijcstra(graph, n - 1);

  for (int i = 0; i < n; ++i) {
    cout << dist1[i] + dist2[i] << endl;
  }
  
  return 0;
}
