#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

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
  vector<int> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<int, int>,
                      vector<pair<int, int> >,
                      greater<pair<int, int> > > que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    int d = que.top().first;
    que.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v]) if (chmin(dist[e.to], dist[v] + e.w)) que.push(make_pair(dist[e.to], e.to));
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[--u].emplace_back(--v, w);
    graph[v].emplace_back(u, w);
  }

  auto dist = dijcstra(graph, 0);
  for (auto d : dist) cout << (d < INF ? d : -1) << endl;
  return 0;
}
