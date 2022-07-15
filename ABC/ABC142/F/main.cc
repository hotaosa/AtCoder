#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr int INF = 1 << 30;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<int> bfs(const vector<vector<int> > &graph, int s) {
  int n = graph.size();
  vector<int> dist(n, INF);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == INF) { dist[nv] = dist[v] + 1; que.push(nv); }
    }
  }
  return dist;
}

vector<int> recover(const vector<vector<int> > &graph, const vector<int> &dist, int s) {
  vector<int> res = {s};
  int v = s, d = dist[s];  
  while (d != 0) {
    int nv = -1;
    for (int nnv : graph[v]) if (dist[nnv] == dist[v] - 1) nv = nnv;
    res.push_back(nv);
    v = nv;
    --d;
  }
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n), rev(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    rev[v].push_back(u);
  }

  pair<int, pair<int, int> > cur = {INF, {-1, -1}};
  for (int v = 0; v < n; ++v) {
    for (int s : graph[v]) {
      auto dist = bfs(graph, s);
      chmin(cur, {++dist[v], {s, v}});
    }
  }

  if (cur.first == INF) cout << "-1" << endl;
  else {
    int s = cur.second.first;
    int t = cur.second.second;
    auto dist = bfs(graph, s);
    auto res = recover(rev, dist, t);
    cout << res.size() << endl;
    for (int r : res) cout << r + 1 << endl;
  }
  return 0;
}