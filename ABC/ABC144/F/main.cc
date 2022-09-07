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
  }
  
  vector<vector<double> > dp(n, vector<double>(n, 1.0e20));
  for (int i = 0; i < n; ++i) if (graph[i].size() != 1) dp[n - 1][i] = 0.0;

  for (int i = n - 2; i >= 0; --i) {
    int siz = graph[i].size();
    for (int j = n - 1; j > i; --j) {
      if (graph[j].size() == 1) continue;
      dp[i][j] = 0.0;
      for (int k : graph[i]) dp[i][j] += dp[k][j];
      dp[i][j] = dp[i][j] / siz + 1.0;
    }
    for (int j = i - 1; j >= 0; --j) if (graph[j].size() != 1) dp[i][j] = dp[i][n - 1];
    if (siz > 1) {
      double sum = 0.0;
      for (int j : graph[i]) sum += dp[j][i];
      for (int j : graph[i]) chmin(dp[i][i], (sum - dp[j][i]) / (siz - 1) + 1.0);
    }    
  }

  double res = 1.0e20;
  for (int i = 0; i < n; ++i) chmin(res, dp[0][i]);
  printf("%.10f\n", res);
  return 0;
}
