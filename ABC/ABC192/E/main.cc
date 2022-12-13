#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  int to;
  long long w, m;
  Edge(int to, long long w, long long m) : to(to), w(w), m(m) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<long long> Dijcstra(const vector<vector<Edge> > &graph, const int &s) {
  const int n = graph.size();
  vector<long long> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<> > pque;
  pque.emplace(0, s);

  while (!pque.empty()) {
    auto [d, v] = pque.top();
    pque.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], (d + e.m - 1) / e.m * e.m + e.w)) {
        pque.emplace(dist[e.to], e.to);
      }
    }
  }

  return dist;
}

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  --x; --y;

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long t, k;
    cin >> u >> v >> t >> k;
    graph[--u].emplace_back(--v, t, k);
    graph[v].emplace_back(u, t, k);
  }

  auto dist = Dijcstra(graph, x);
  cout << (dist[y] < INF ? dist[y] : -1) << endl;  
  return 0;
}
