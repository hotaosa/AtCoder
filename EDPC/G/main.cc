#include <iostream>
#include <vector>
#include <algorithm>

void toposort(const std::vector<std::vector<int> > &graph,
              std::vector<int> &v, std::vector<bool> &used, int i) {
  used[i] = true;
  for (int next : graph[i]) {
    if (used[next]) continue;
    toposort(graph, v, used, next);
  }
  v.push_back(i);
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
  }

  std::vector<int> v;
  std::vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    if (used[i]) continue;
    toposort(graph, v, used, i);
  }
  std::reverse(v.begin(), v.end());

  int res = 0;
  std::vector<int> dp(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int next : graph[v[i]]) {
      dp[next] = std::max(dp[next], dp[v[i]] + 1);
      res = std::max(res, dp[next]);
    }
  }

  std::cout << res << std::endl;
  return 0;  
}
