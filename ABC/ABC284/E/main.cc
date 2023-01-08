#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool DFS(const vector<vector<int> > &graph, const int &v, const int &par, set<int> *se, int *res) {
  se->insert(v);
  for (auto nv : graph[v]) {
    if (nv == par || se->count(nv)) continue;
    if (DFS(graph, nv, v, se, res)) return true;
  }
  se->erase(v);
  return ++(*res) == 1000000;
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

  int res = 0;
  set<int> se;
  DFS(graph, 0, -1, &se, &res);
  cout << res << endl;
  return 0;
}
