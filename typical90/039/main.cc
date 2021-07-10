#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int> > &graph, std::vector<long long> &dp, int v, int par) {
  dp[v] = 1;
  for (int n_v : graph[v]) {
    if (n_v == par) continue;
    dfs(graph, dp, n_v, v);
    dp[v] += dp[n_v];
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > graph(n);
  std::vector<std::pair<int, int> > vp;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    vp.push_back(std::make_pair(a, b));
    graph[a].push_back(b);
    graph[b].push_back(a);    
  }

  std::vector<long long> dp(n, 0LL);
  dfs(graph, dp, 0, -1);
  long long res = 0;
  for (int i = 0; i < n - 1; ++i) {
    int a = vp[i].first;
    int b = vp[i].second;
    long long r = std::min(dp[a], dp[b]);
    res += r * (n - r);
  }
  std::cout << res << std::endl;
  return 0;
}
