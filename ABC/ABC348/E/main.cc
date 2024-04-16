#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }
  vector<ll> c(n);
  for (auto &e : c) cin >> e;

  vector<ll> dp_d(n, 0), dp_c(n, 0);
  auto DFS1 = [&](auto DFS1, int v, int par) -> void {
    dp_c[v] = c[v];
    for (int nv : graph[v]) {
      if (nv == par) continue;
      DFS1(DFS1, nv, v);
      dp_d[v] += dp_d[nv] + dp_c[nv];
      dp_c[v] += dp_c[nv];
    }
  };
  DFS1(DFS1, 0, -1);

  vector<ll> dp(n, 0);
  auto DFS2 = [&](auto DFS2, int v, int par, ll p_d, ll p_c) -> void {
    dp[v] = dp_d[v] + p_d;
    for (int nv : graph[v]) {
      if (nv == par) continue;
      ll nx_p_c = p_c + dp_c[v] - dp_c[nv];
      ll nx_p_d = p_d + dp_d[v] - (dp_d[nv] + dp_c[nv]) + nx_p_c;
      DFS2(DFS2, nv, v, nx_p_d, nx_p_c);
    }
  };
  DFS2(DFS2, 0, -1, 0, 0);

  cout << *min_element(begin(dp), end(dp)) << endl;
  return 0;
}
