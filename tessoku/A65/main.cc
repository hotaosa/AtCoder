#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int> > graph(n);
  for (int i = 1; i < n; ++i)  {
    int a;
    cin >> a;
    graph[--a].push_back(i);
  }

  vector<int> res(n, 0);
  auto dfs = [&](auto dfs, int v) -> int {
    for (auto nv : graph[v]) {
      res[v] += dfs(dfs, nv) + 1;
    }
    return res[v];
  };

  dfs(dfs, 0);
  for (auto r : res) cout << r << " ";
  cout << endl;  
  return 0;
}
