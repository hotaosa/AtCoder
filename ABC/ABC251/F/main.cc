#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

void dfs(const vector<vector<int> > &graph, vector<bool> &used, int v) {
  used[v] = true;
  for (int nv : graph[v]) {
    if (!used[nv]) {
      cout << v + 1 << " " << nv + 1 << endl;
      dfs(graph, used, nv);
    }
  }
}

void bfs(const vector<vector<int> > &graph) {
  int n = graph.size();
  vector<bool> used(n, false);
  used[0] = true;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (!used[nv]) {
        cout << v + 1 << " " << nv + 1 << endl;
        used[nv] = true;
        que.push(nv);
      }
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<bool> used(n, false);
  dfs(graph, used, 0);  
  bfs(graph);
  return 0;
}
