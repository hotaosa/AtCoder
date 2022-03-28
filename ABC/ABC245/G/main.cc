#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr long long INF = 1LL << 60;

struct Edge {
  int to;
  long long w;
  Edge(int to_, long long w_) : to(to_), w(w_) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m, k, l;
  cin >> n >> m >> k >> l;

  vector<int> a(n), b(l);
  for (auto &p : a) { cin >> p; --p; }
  for (auto &p : b) { cin >> p; --p; }

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long c;
    cin >> u >> v >> c;
    graph[--u].emplace_back(--v, c);
    graph[v].emplace_back(u, c);
  }

  vector<vector<pair<long long, int> > > dist(n, vector<pair<long long, int> >(2, {INF, -1}));
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, greater<tuple<long long, int, int> > > pque;

  auto update = [&](long long w, int v, int from) -> bool {
    if (dist[v][0].second == from) return chmin(dist[v][0], {w, from});
    if (dist[v][1].second == from) {
      if (chmin(dist[v][1], {w, from})) {
        if (dist[v][1] < dist[v][0]) swap(dist[v][0], dist[v][1]);
        return true;
      }
      return false;
    }
    if (chmin(dist[v][1], {w, from})) {
      if (dist[v][1] < dist[v][0]) swap(dist[v][0], dist[v][1]);
      return true;
    }
    return false;
  };

  for (int v : b) if (update(0, v, a[v])) pque.push({0, v, a[v]});
  while (!pque.empty()) {
    long long cost = get<0>(pque.top());
    int v = get<1>(pque.top());
    int from = get<2>(pque.top());    
    pque.pop();    
    if (from == dist[v][0].second && cost > dist[v][0].first) continue;
    if (from == dist[v][1].second && cost > dist[v][1].first) continue;
    if (from != dist[v][0].second && from != dist[v][1].second) continue;    
    for (auto e : graph[v]) {
      if (update(cost + e.w, e.to, from)) pque.push({cost + e.w, e.to, from});
    }
  }
  
  for (int i = 0; i < n; ++i) {
    if (dist[i][0].second == -1) cout << "-1" << " ";
    else if (dist[i][0].second != a[i]) cout << dist[i][0].first << " ";
    else if (dist[i][1].second == -1) cout << "-1" << " ";
    else cout << dist[i][1].first << " ";
  }
  cout << endl;
  return 0;
}
