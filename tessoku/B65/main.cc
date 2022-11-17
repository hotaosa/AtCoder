#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, t;
  cin >> n >> t;

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  vector<int> res(n, 0);
  vector<bool> visited(n, 0);
  auto dfs = [&](auto dfs, int v) -> int {
    visited[v] = true;
    for (int nv : graph[v]) {
      if (visited[nv]) continue;
      chmax(res[v], dfs(dfs, nv));
    }
    return res[v] + 1;
  };

  dfs(dfs, --t);
  for (auto r : res) cout << r << " ";
  cout << endl;
  return 0;
}
