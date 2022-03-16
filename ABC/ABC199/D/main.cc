#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  vector<bool> used(n, false);
  vector<vector<int> > order;

  auto dfs1 = [&](auto dfs1, int v, vector<int> &cur) -> void {
    cur.push_back(v);
    used[v] = true;
    for (int nv : graph[v]) {
      if (!used[nv]) dfs1(dfs1, nv, cur);
    }
  };

  for (int i = 0; i < n; ++i) {    
    if (!used[i]) {
      vector<int> cur;
      dfs1(dfs1, i, cur);
      order.push_back(cur);
    }
  }
  
  vector<int> c(n, -1);
  long long res = 1;
  int cnt = 0;

  auto dfs2 = [&](auto dfs2, vector<int> &o, long long &add, int col, int p) -> void {
    ++cnt;
    int v = o[p];
    for (int nv : graph[v]) if (c[nv] == col) return;
    c[v] = col;    
    if (p == (int)o.size() - 1) ++add;
    else for (int i = 0; i < 3; ++i) dfs2(dfs2, o, add, i, p + 1);
    c[v] = -1;    
  };  

  for (auto o : order) {
    long long add = 0;
    dfs2(dfs2, o, add, 0, 0);    
    res *= add * 3;    
  }
  cout << res << endl;
  return 0;
}