#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
  int to;
  long long w;
  Edge(int to_, long long w_) : to(to_), w(w_) { }
};

void dfs(const vector<vector<Edge> > &graph, const vector<int> &d, vector<vector<long long> > &dp, int v, int p) {
  vector<long long> vec;
  for (auto e : graph[v]) {
    if (e.to == p) continue;
    dfs(graph, d, dp, e.to, v);
    vec.push_back(dp[e.to][0] + e.w - dp[e.to][1]);
    dp[v][0] += dp[e.to][1];
    dp[v][1] += dp[e.to][1];
  }
  sort(vec.begin(), vec.end(), greater<>());  
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (vec[i] <= 0) break;
    if (i < d[v] - 1) dp[v][0] += vec[i];
    if (i < d[v]) dp[v][1] += vec[i];
  }
  if (d[v] == 0) dp[v][0] = -(1LL << 60);
}

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  for (auto &p : d) cin >> p;

  vector<vector<Edge> > graph(n);  
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    graph[--u].emplace_back(--v, w);
    graph[v].emplace_back(u, w);
  }

  vector<vector<long long> > dp(n, vector<long long>(2, 0));
  dfs(graph, d, dp, 0, -1);
  cout << dp[0][1] << endl;
  return 0;
}