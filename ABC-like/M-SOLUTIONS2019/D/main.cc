#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  vector<int> c(n);
  for (auto &p : c) cin >> p;
  sort(c.begin(), c.end(), greater<>());

  queue<int> que;
  for (int i = 1; i < n; ++i) que.push(c[i]);

  vector<int> res(n, -1);
  res[0] = c[0];
  int sum = 0;

  auto dfs = [&](auto dfs, int v, int p) -> void {
    for (int nv : graph[v]) {
      if (nv == p) continue;
      res[nv] = que.front();
      sum += res[nv];
      que.pop();
      dfs(dfs, nv, v);
    }
  };

  dfs(dfs, 0, -1);
  cout << sum << endl;
  for (auto &p : res) cout << p << " ";
  cout << endl;
  return 0;
}
