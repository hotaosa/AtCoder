#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (b < a) { a = b; return true; }
  return false;
}

struct Dist {
  int d, t;
  Dist(int d, int t) : d(d), t(t) { }
  bool operator<(const Dist &rhs) const {
    if (d != rhs.d) return d < rhs.d;
    return t > rhs.t;
  }
  Dist operator+(const Dist &rhs) const {
    return Dist(d + rhs.d, t + rhs.t);
  }
};

struct Edge {
  int to, w, t;
  Edge(int to, int w, int t) : to(to), w(w), t(t) { }
};

vector<Dist> dijcstra(const vector<vector<Edge> > &graph, int s) {
  int n = graph.size();
  vector<Dist> dist(n, Dist(1 << 30, -1));
  dist[s] = Dist(0, 0);

  priority_queue<pair<Dist, int>,
                      vector<pair<Dist, int> >,
                      greater<pair<Dist, int> > > que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    Dist d = que.top().first;
    que.pop();
    if (dist[v] < d) continue;
    for (auto e : graph[v]) if (chmin(dist[e.to], dist[v] + Dist(e.w, e.t))) que.push(make_pair(dist[e.to], e.to));
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    graph[--u].emplace_back(--v, c, d);
    graph[v].emplace_back(u, c, d);
  }

  auto dist = dijcstra(graph, 0);
  cout << dist[n - 1].d << " " << dist[n - 1].t << endl;  
  return 0;
}
