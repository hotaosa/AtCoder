#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::dsu uf(n);
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    uf.merge(--u, --v);
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<int> col(n, -1);
  bool all_bipartite = true;

  auto dfs = [&](auto dfs, int v) -> void {
    for (auto nv : graph[v]) {
      if (col[nv] == -1) {
        col[nv] = col[v] ^ 1;
        dfs(dfs, nv);
      } else {
        all_bipartite &= col[nv] != col[v];
      }
    }
  };

  for (int i = 0; i < n; ++i) {
    if (uf.leader(i) == i) {
      col[i] = 0;
      dfs(dfs, i);
    }
  }

  if (!all_bipartite) {
    cout << "0" << endl;
    return 0;
  }

  vector<vector<long long> > cnt(n, vector<long long>(2, 0));
  for (int i = 0; i < n; ++i) ++cnt[uf.leader(i)][col[i]];

  long long res = (long long)n * (long long)(n - 1) / 2 - m;
  for (int i = 0; i < n; ++i) {
    res -= cnt[i][0] * (cnt[i][0] - 1) / 2;
    res -= cnt[i][1] * (cnt[i][1] - 1) / 2;
  }

  cout << res << endl;  
  return 0;
}
