#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint998244353;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  auto DFS = [&](auto DFS, int v, int p) -> vector<vector<mint> > {
    vector dv(2, vector<mint>(2, 0));
    dv[0][0] = dv[1][1] = 1;
    for (int u : graph[v]) {
      if (u == p) continue;
      auto du = DFS(DFS, u, v);
      int sv = dv.size(), su = du.size();
      int siz = sv + su - 1;
      vector dp(siz, vector<mint>(2, 0));
      for (int i = 0; i < sv; ++i) {
        for (int j = 0; j < su; ++j) {
          dp[i + j][0] += dv[i][0] * (du[j][0] + du[j][1]);
          dp[i + j][1] += dv[i][1] * du[j][0];
          if (i + j > 0) {
            dp[i + j - 1][1] += dv[i][1] * du[j][1];
          }
        }
      }
      swap(dv, dp);
    }
    return dv;
  };

  auto dp = DFS(DFS, 0, -1);
  for (int i = 1; i <= n; ++i) {
    mint res = dp[i][0] + dp[i][1];
    cout << res.val() << endl;
  }
  
  return 0;
}
