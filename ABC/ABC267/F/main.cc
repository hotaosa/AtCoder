#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

pair<int, int> farthest(const vector<vector<int> > &graph, int s) {
  int n = graph.size();
  vector<int> dist(n, n);
  dist[s] = 0;
  pair<int, int> ret(0, s);
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] < n) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
      chmax(ret, {dist[nv], nv});
    }
  }
  return ret;
}

pair<int, pair<int, int> > diameter(const vector<vector<int> > &graph) {
  auto [d1, x] = farthest(graph, 0);
  auto [d2, y] = farthest(graph, x);
  return {d2, {x, y}};
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  
  int q;
  cin >> q;
  vector<int> res(q, -1);
  vector<vector<pair<int, int> > > query(n);
  for (int i = 0; i < q; ++i) {
    int u, k;
    cin >> u >> k;
    query[--u].emplace_back(k, i);
  }

  deque<int> dq;
  auto dfs = [&](auto dfs, int v, int p) -> void {
    dq.push_front(v);
    for (auto qu : query[v]) {
      if ((int)dq.size() > qu.first) res[qu.second] = dq[qu.first] + 1;
    }
    for (int nv : graph[v]) if (nv != p) dfs(dfs, nv, v);
    dq.pop_front();
  };

  auto [d, pa] = diameter(graph);
  auto [x, y] = pa;
  dfs(dfs, x, -1);
  dfs(dfs, y, -1);

  for (int r : res) cout << r << endl;
  return 0;
}
