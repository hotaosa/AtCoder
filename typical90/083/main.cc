#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
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

  int sqm = (int)sqrt(m);
  vector<int> large;
  vector<bool> is_large(n, false);
  for (int i = 0; i < n; ++i) {
    if ((int)graph[i].size() > sqm) {
      is_large[i] = true;
      large.push_back(i);      
    }
  }

  vector<vector<int> > connected_large(n);
  for (int v = 0; v < n; ++v) for (int nv : graph[v]) if (is_large[nv]) connected_large[v].push_back(nv);

  int q;
  cin >> q;
  vector<pair<int, int> > color(n, {q, 1}), large_memo(n, {q, 1});
  while (q--) {
    int x, y;
    cin >> x >> y;    
    auto res = color[--x];
    for (int v : connected_large[x]) chmin(res, large_memo[v]);
    cout << res.second << endl;
    if (is_large[x]) large_memo[x] = {q, y};
    else for (int nv : graph[x]) color[nv] = {q, y};
    color[x] = {q, y};
  }
  return 0;
}
