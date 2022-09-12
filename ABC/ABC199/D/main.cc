#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

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

  vector<vector<int> > nodes;
  vector<bool> seen(n, false);  

  auto dfs1 = [&](auto dfs1, int v) -> void {
    seen[v] = true;
    nodes[nodes.size() - 1].push_back(v);
    for (int nv : graph[v]) if (!seen[nv]) dfs1(dfs1, nv);
  };

  for (int i = 0; i < n; ++i) {
    if (!seen[i]) {
      nodes.push_back(vector<int>(0));
      dfs1(dfs1, i);
    }
  }

  vector<int> col(n, -1);
  auto dfs2 = [&](auto dfs2, vector<int> &vec, int i, int &cur) -> void {
    if (i == vec.size()) { ++cur; return; }

    int v = vec[i];
    set<int> se;
    for (int nv : graph[v]) se.insert(col[nv]);
    for (int c = 0; c < 3; ++c) {
      if (!se.count(c)) {
        col[v] = c;
        dfs2(dfs2, vec, i + 1, cur);
      }
    }
    col[v] = -1;
  };

  long long res = 1;
  for (auto vec : nodes) {
    int cur = 0;
    dfs2(dfs2, vec, 0, cur);
    res *= cur;
  }
  cout << res << endl;  
  return 0;
}
