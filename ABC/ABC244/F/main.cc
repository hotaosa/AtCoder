#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<vector<long long> > dp(n, vector<long long>(1 << n, -1));
  queue<pair<int, int> > que;
  for (int i = 0; i < n; ++i) {
    dp[i][1 << i] = 1;
    que.push(make_pair(i, 1 << i));
  }

  while (!que.empty()) {
    int v = que.front().first;
    int bit = que.front().second;
    que.pop();
    for (int nv : graph[v]) {
      if (dp[nv][bit ^ (1 << nv)] == -1) {
        dp[nv][bit ^ (1 << nv)] = dp[v][bit] + 1;
        que.push(make_pair(nv, bit ^ (1 << nv)));
      }
    }
  }

  long long res = 0;
  for (int bit = 1; bit < (1 << n); ++bit) {
    long long add = 1LL << 60;
    for (int v = 0; v < n; ++v) add = min(add, dp[v][bit]);
    res += add;
  }
  cout << res << endl;
  return 0;
}
