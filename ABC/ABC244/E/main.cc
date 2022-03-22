#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n, m, k, s, t, x;  
  cin >> n >> m >> k >> s >> t >> x;
  --s; --t; --x;
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<vector<vector<mint> > > dp(k + 1, vector<vector<mint> > (n, vector<mint>(2, 0)));
  dp[0][s][0] = 1;
  for (int i = 0; i < k; ++i) {
    for (int v = 0; v < n; ++v) {
      for (int nv : graph[v]) {
        if (nv == x) {
          dp[i + 1][nv][0] += dp[i][v][1];
          dp[i + 1][nv][1] += dp[i][v][0];
        } else {
          dp[i + 1][nv][0] += dp[i][v][0];
          dp[i + 1][nv][1] += dp[i][v][1];
        }
      }
    }
  }

  cout << dp[k][t][0].val() << endl;
  return 0;
}
