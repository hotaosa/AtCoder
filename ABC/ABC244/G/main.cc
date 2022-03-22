#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int> > graph(n);
  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    if (!uf.same(--u, --v)) {
      uf.merge(u, v);
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
  }

  string s;
  cin >> s;
  vector<int> ss(n);
  for (int i = 0; i < n; ++i) ss[i] = s[i] - '0';
  vector<int> cnt(n, 0);
  deque<int> res;

  auto dfs = [&](auto dfs, int v, int p) -> void {
    res.push_back(v);
    cnt[v] ^= 1;
    for (int nv : graph[v]) {
      if (nv != p) {
        dfs(dfs, nv, v);
      }
    }
    if (cnt[v] != ss[v] && p != -1) {
      res.push_back(p);
      res.push_back(v);
      cnt[p] ^= 1;
      cnt[v] ^= 1;
    }
    if (p != -1) {
      res.push_back(p);
      cnt[p] ^= 1;
    }
  };

  dfs(dfs, 0, -1);
  if (cnt[0] != ss[0]) res.pop_front();
  cout << res.size() << endl;
  for (auto &p : res) cout << p + 1 << " ";
  cout << endl;
  return 0;
}
