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

vector<int> Dijcstra(const vector<vector<Edge> > &graph, const int &s) {
  const int n = graph.size();
  vector<int> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pque;
  pque.emplace(0, s);

  while (!pque.empty()) {
    auto [d, v] = pque.top();
    pque.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], dist[v] + e.w)) {
        pque.emplace(dist[e.to], e.to);
      }
    }
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[--a].emplace_back(--b, c);
    graph[b].emplace_back(a, c);
  }

  auto dist1 = Dijcstra(graph, 0);
  auto dist2 = Dijcstra(graph, n - 1);

  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (dist1[i] + dist2[i] == dist1[n - 1]) ++res;
  }

  cout << res << endl;  
  return 0;
}
