#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > graph(n);
  vector<int> u(n), v(n);
  for (int i = 0; i < n - 1; ++i) {
    cin >> u[i] >> v[i];
    graph[--u[i]].push_back(--v[i]);
    graph[v[i]].push_back(u[i]);
  }

  vector<long long> cnt(n, 0);
  auto dfs = [&](auto dfs, int v, int p) -> long long {
    for (int nv : graph[v]) {
      if (nv == p) continue;
      cnt[v] += dfs(dfs, nv, v);
    }
    return ++cnt[v];
  };

  dfs(dfs, 0, -1);
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[u[i]] > cnt[v[i]]) swap(u[i], v[i]);
    res += cnt[u[i]] * (n - cnt[u[i]]);
  }
  cout << res << endl;
  return 0;
}
