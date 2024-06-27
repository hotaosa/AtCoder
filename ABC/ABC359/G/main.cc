#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
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

  vector<int> a(n);
  for (auto &e : a) {
    cin >> e;
    --e;
  }

  vector<ll> depth(n, 0);
  vector<map<int, ll>> cnt(n);
  vector<map<int, ll>> depth_sum(n);

  ll res = 0;

  auto DFS = [&](auto DFS, int v, int p = -1) -> void {
    for (int nv : graph[v]) {
      if (nv != p) {
        depth[nv] = depth[v] + 1;
        DFS(DFS, nv, v);
      }
    }

    res += depth_sum[v][a[v]] - depth[v] * cnt[v][a[v]];
    ++cnt[v][a[v]];
    depth_sum[v][a[v]] += depth[v];

    if (p == -1) return;
    if (size(cnt[p]) < size(cnt[v])) {
      swap(cnt[v], cnt[p]);
      swap(depth_sum[v], depth_sum[p]);
    }
    for (auto [c, val] : cnt[v]) {
      res += (depth_sum[v][c] - depth[p] * cnt[v][c]) * cnt[p][c];
      res += (depth_sum[p][c] - depth[p] * cnt[p][c]) * cnt[v][c];
      cnt[p][c] += cnt[v][c];
      depth_sum[p][c] += depth_sum[v][c];
    }
  };
  DFS(DFS, 0);

  cout << res << endl;
  return 0;
}