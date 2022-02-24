#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using mint = atcoder::modint1000000007;

int main() {
  int n, k;
  cin >> n >> k;

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  vector<mint> fact(k + 1);
  fact[0] = 1;
  for (int i = 1; i <= k; ++i) fact[i] = fact[i - 1] * i;

  vector<int> cnt(n, 0);
  mint res = 1;
  auto dfs = [&](auto dfs, int v, int p, int c) -> void {
    if (p == -1) res *= k;
    else res *= k - c;

    int cnt = 1;
    if (p != -1) ++cnt;
    for (int nv : graph[v]) {      
      if (nv == p) continue;
      dfs(dfs, nv, v, cnt++);
    }
  };

  dfs(dfs, 0, -1, 0);
  cout << res.val() << endl;
  return 0;
}
