#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

struct Edge {
  int src, to;
  int w;
  Edge(int src_, int to_, int w_) : src(src_), to(to_), w(w_) { }
  Edge(int to_, int w_) : src(-1), to(to_), w(w_) { }
  Edge(int to_) : src(-1), to(to_), w(1) { }
  bool operator<(const Edge other) const { return w < other.w; }
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
    int u, v, c;
    cin >> u >> v >> c;
    graph[--u].emplace_back(--v, c);
    graph[v].emplace_back(u, c);
  }

  vector<int> dist1 = dijcstra(graph, 0);
  vector<int> dist2 = dijcstra(graph, n - 1);
  for (int i = 0; i < n; ++i) cout << dist1[i] + dist2[i] << endl;
  return 0;
}
