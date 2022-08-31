#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    char ch;
    cin >> ch;
    c[i] = ch == 'a' ? 0 : 1;
  }

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<vector<mint> > dp(n, vector<mint>(3, 0));

  auto dfs = [&](auto dfs, int v, int p) -> void {    
    vector<mint> d(3, 1);
    for (int nv : graph[v]) {
      if (nv == p) continue;
      dfs(dfs, nv, v);
      d[c[v]] *= dp[nv][c[v]] + dp[nv][2];
      d[2] *= dp[nv][c[v]] + dp[nv][1 - c[v]] + dp[nv][2] * 2;
    }
    dp[v][c[v]] = d[c[v]];
    dp[v][2] = d[2] - d[c[v]];
  };

  dfs(dfs, 0, -1);
  cout << dp[0][2].val() << endl;  
  return 0;
}
