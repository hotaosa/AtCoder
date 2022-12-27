#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<int> a(n), b(k);
  for (auto &p : a) { cin >> p; --p; }
  for (auto &p : b) { cin >> p; --p; }

  const int INF = 1 << 30;
  vector<int> dp(n, INF);
  dp[0] = a[0] == b[0] ? 1 : 0;

  deque<int> que;
  que.push_back(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop_front();
    for (int nv : graph[v]) {
      if (dp[nv] < INF) continue;
      if (a[nv] == b[dp[v]]) {
        dp[nv] = dp[v] + 1;
        que.push_back(nv);
      } else {
        dp[nv] = dp[v];
        que.push_front(nv);
      }
    }
  }
    
  cout << (dp[n - 1] == k ? "Yes" : "No") << endl;
  return 0;
}
