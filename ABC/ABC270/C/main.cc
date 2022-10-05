#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool dfs(const vector<vector<int> > &graph, int v, int p, int g, vector<int> &res) {
  res.push_back(v + 1);
  if (v == g) return true;
  for (int nv : graph[v]) {
    if (nv == p) continue;
    if (dfs(graph, nv, v, g, res)) return true;
  }
  res.pop_back();
  return false;
}

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<int> res;
  dfs(graph, --x, -1, --y, res);
  for (auto &p : res) cout << p << " ";
  cout << endl;
  return 0;
}
