#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  int root = -1;
  vector<bool> is_target(n, false);
  for (int i = 0; i < k; ++i) {
    int v;
    cin >> v;
    is_target[--v] = true;
    if (i == 0) root = v;
  }

  vector<pair<int, int>> dp(n, {0, 0});
  auto DFS = [&](auto DFS, int v, int p) -> void {
    dp[v].first = 1;
    if (is_target[v]) dp[v].second = 1;
    for (int nv : graph[v]) {
      if (nv == p) continue;
      DFS(DFS, nv, v);
      if (dp[nv].second) {
        dp[v].first += dp[nv].first;
        dp[v].second += dp[nv].second;
      }
    }
  };
  DFS(DFS, root, -1);

  cout << dp[root].first << endl;
  return 0;
}