#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  auto judge = [&](long long k) -> bool {
    vector<long long> cost(n, 0);
    queue<int> que;
    for (int v = 0; v < n; ++v) {
      for (int nv : graph[v]) cost[v] += a[nv];
      if (cost[v] <= k) que.push(v);
    }
    int cnt = 0;
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      ++cnt;
      for (int nv : graph[v]) {
        if (cost[nv] <= k) continue;
        cost[nv] -= a[v];
        if (cost[nv] <= k) que.push(nv);
      }
    }
    return cnt == n;    
  };

  long long l = -1, r = 1LL << 60;
  while (r - l > 1) {
    long long mid = (r + l) / 2;
    if (judge(mid)) r = mid;
    else l = mid;
  }
  cout << r << endl;  
  return 0;
}
