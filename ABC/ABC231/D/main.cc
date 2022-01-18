#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool dfs(const vector<vector<int> > &graph, vector<bool> &used, int v, int p = -1) {
  used[v] = true;
  for (int nv : graph[v]) {
    if (nv == p) continue;
    if (used[nv]) return false;
    if (!dfs(graph, used, nv, v)) return false;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n, 0);
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  vector<bool> used(n, false);  
  for (int i = 0; i < n; ++i) {
    if (graph[i].size() > 2) { cout << "No" << endl; return 0; }
    if (used[i]) continue;
    if (!dfs(graph, used, i)) { cout << "No" << endl; return 0; }
  }

  cout << "Yes" << endl;
  return 0;
}
