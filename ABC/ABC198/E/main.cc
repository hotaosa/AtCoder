#include <bits/stdc++.h>

void dfs(const std::vector<std::vector<int>> &graph,
         const std::vector<int> &color, std::vector<int> &cnt,
         int v, int par, std::vector<int> &res) {
  if (cnt[color[v]] == 0) res.push_back(v + 1);
  ++cnt[color[v]];
  for (int next_v : graph[v]) {
    if (next_v == par) continue;
    dfs(graph, color, cnt, next_v, v, res);
  }
  --cnt[color[v]];  
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  std::vector<int> color(n);
  std::vector<int> cnt(100010, 0);
  for (int i = 0; i < n; ++i) std::cin >> color[i];
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    --a;
    --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  std::vector<int> res;
  dfs(graph, color, cnt, 0, -1, res);
  std::sort(res.begin(), res.end());
  for (auto r : res) std::cout << r << std::endl;
  return 0;
}

