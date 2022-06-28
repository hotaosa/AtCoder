#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<pair<int, int> > > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    graph[--a].emplace_back(--b, i);
    graph[b].emplace_back(a, i);
  }

  auto dfs = [&](auto dfs, vector<int> &edges, int v, int p, int g) -> bool {    
    if (v == g) return true;
    for (auto e : graph[v]) {
      if (e.first == p) continue;
      edges.push_back(e.second);
      if (dfs(dfs, edges, e.first, v, g)) return true;
      edges.pop_back();
    }
    return false;
  };

  int m;
  cin >> m;  
  vector<int> add(n - 1, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    vector<int> edges;
    dfs(dfs, edges, --u, -1, --v);
    for (int e : edges) add[e] |= (1 << i);
  }  

  vector<vector<long long> > dp(n, vector<long long>(1 << m, 0));
  dp[0][0] = 1;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < (1 << m); ++j) {
      if (dp[i][j] == 0) continue;
      dp[i + 1][j] += dp[i][j];      
      dp[i + 1][j | add[i]] += dp[i][j];
    }
  }

  cout << dp[n - 1].back() << endl;  
  return 0;
}