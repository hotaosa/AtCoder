#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int Solve() {
  int n, m;
  cin >> n >> m;
  vector<int> c(n);
  for (auto &p : c) cin >> p;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  vector dp(n, vector<int>(n, -1));
  dp[0][n - 1] = 0;
  queue<pair<int, int> > que;
  que.emplace(0, n -1);
  while (!que.empty()) {
    auto [u, v] = que.front();
    que.pop();
    for (int nu : graph[u]) {
      for (int nv : graph[v]) {
        if (c[nu] ^ c[nv] && dp[nu][nv] == -1) {
          dp[nu][nv] = dp[u][v] + 1;
          que.emplace(nu, nv);
        }
      }
    }
  }
  return dp[n - 1][0];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << Solve() << endl;
  }
  return 0;
}
