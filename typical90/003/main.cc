#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

pair<int, int> bfs(const vector<vector<int> > &graph, int s) {
  pair<int, int> ret = {0, s};
  int n = graph.size();
  vector<int> dist(n, -1);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        que.push(nv);
        chmax(ret, {dist[nv], nv});
      }
    }
  }
  return ret;
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

  auto v1 = bfs(graph, 0);
  auto v2 = bfs(graph, v1.second);
  cout << ++v2.first << endl;
  return 0;
}
