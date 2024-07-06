#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;

struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};

pair<ll, int> Farthest(const vector<vector<Edge>> &graph, int s) {
  const int n = size(graph);
  vector<ll> dist(n, INF);
  dist[s] = 0;
  pair<ll, int> ret(0LL, s);
  queue<int> que;
  que.emplace(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto e : graph[v]) {
      if (dist[e.to] < INF) continue;
      dist[e.to] = dist[v] + e.w;
      que.emplace(e.to);
      ret = max(ret, {dist[e.to], e.to});
    }
  }
  return ret;
}

pair<ll, pair<int, int>> Diameter(const vector<vector<Edge>> &graph) {
  auto [d1, x] = Farthest(graph, 0);
  auto [d2, y] = Farthest(graph, x);
  return {d2, {x, y}};
}

int main() {
  int n;
  cin >> n;
  vector<vector<Edge>> graph(n);

  ll res = 0;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    res += w * 2;
    graph[--u].emplace_back(--v, w);
    graph[v].emplace_back(u, w);
  }
  res -= Diameter(graph).first;
  cout << res << endl;
  return 0;
}