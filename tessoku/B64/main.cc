#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

struct Edge {
  int to, w;
  Edge(int to, int w) : to(to), w(w) { }
};

vector<int> dijcstra(const vector<vector<Edge> > &graph, const int &s) {
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

  auto dist = dijcstra(graph, 0);
  vector<int> res;
  auto dfs = [&](auto dfs, int v) -> bool {
    res.push_back(v + 1);
    if (v == n - 1) return true;
    for (auto e : graph[v]) {
      if (dist[e.to] == dist[v] + e.w) {
        if (dfs(dfs, e.to)) return true;
      }
    }
    res.pop_back();
    return false;
  };

  dfs(dfs, 0);
  for (auto r : res) cout << r << " ";
  cout << endl;  
  return 0;
}
