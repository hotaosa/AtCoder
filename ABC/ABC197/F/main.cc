#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

struct Edge {
  int to;
  char ch;
  Edge(int to, char ch) : to(to), ch(ch) { }
};

int main() {
  int n, m;
  cin >> n >> m;

  auto to_p = [&](int u, int v) -> int {
    return u * n + v;
  };

  auto to_uv = [&](int p) -> pair<int, int> {
    return make_pair(p / n, p % n);
  };

  vector<vector<bool> > exist_edge(n, vector<bool>(n, false));

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    char c;
    cin >> u >> v >> c;
    graph[--u].emplace_back(--v, c);
    graph[v].emplace_back(u, c);
    exist_edge[u][v] = exist_edge[v][u] = true;
  }

  vector<int> dist(n * n, INF);
  int s = to_p(0, n - 1);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int p = que.front();
    int u = to_uv(p).first;
    int v = to_uv(p).second;
    que.pop();
    for (auto eu : graph[u]) {
      for (auto ev : graph[v]) {
        if (eu.ch == ev.ch) {
          int np = to_p(eu.to, ev.to);
          if (dist[np] == INF) {
            dist[np] = dist[p] + 1;
            que.push(np);
          }          
        }
      }
    }
  }

  int res = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (dist[to_p(i, j)] == INF) continue;
      if (i == j) res = min(res, dist[to_p(i, j)] * 2);
      else if (exist_edge[i][j]) res = min(res, dist[to_p(i, j)] * 2 + 1);
    }
  }

  cout << (res < INF ? res : -1) << endl;
  return 0;
}
