#include <iostream>
#include <vector>

void dfs(const std::vector<std::vector<int>> &graph, std::vector<int> &col, int v,
         std::vector<std::vector<int>> &vec) {
  for (int n_v : graph[v]) {
    if (col[n_v] != -1) continue;
    col[n_v] = 1 - col[v];
    vec[col[n_v]].push_back(n_v);
    dfs(graph, col, n_v, vec);
  }
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    graph[b].push_back(a);
  }

  std::vector<int> col(n, -1);
  col[0] = 0;
  std::vector<std::vector<int>> vec(2);
  dfs(graph, col, 0, vec);
  int c = 0;
  if ((int)vec[0].size() < n / 2) ++c;
  for (int i = 0; i < n / 2; ++i) std::cout << vec[c][i] + 1 << " ";  
  std::cout << std::endl;
  return 0;  
}
