#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  int src, to;
  long long w;
  Edge(int src_, int to_, long long w_) : src(src_), to(to_), w(w_) { }
  Edge(int to_, long long w_) : src(-1), to(to_), w(w_) { }
  Edge(int to_) : src(-1), to(to_), w(1) { }
  bool operator<(const Edge other) const { return w < other.w; }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<long long> dijcstra(const vector<vector<Edge> > &graph, int s) {
  int n = graph.size();
  vector<long long> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<long long, int>,
                      vector<pair<long long, int> >,
                      greater<pair<long long, int> > > que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    long long d = que.top().first;
    que.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v]) if (chmin(dist[e.to], dist[v] + e.w)) que.push(make_pair(dist[e.to], e.to));
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> h(n);
  for (auto &p : h) cin >> p;  
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    if (h[u] < h[v]) swap(u, v);
    graph[u].emplace_back(v, 0);
    graph[v].emplace_back(u, h[u] - h[v]);
  }
  vector<long long> dist = dijcstra(graph, 0);
  long long res = 0;
  for (int i = 0; i < n; ++i) res = max(res, h[0] - h[i] - dist[i]);
  cout << res << endl;
  return 0;
}
