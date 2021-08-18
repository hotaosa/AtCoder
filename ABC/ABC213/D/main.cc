#include <iostream>
#include <vector>
#include <set>

void dfs(const std::vector<std::set<int> > &graph, std::vector<bool> &used, std::vector<int> &res,
         int v, int par) {
  res.push_back(v);
  used[v] = true;
  for (int nx : graph[v]) {
    if (used[nx]) continue;
    dfs(graph, used, res, nx, v);
  }
  res.push_back(par);
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::set<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].insert(--b);
    graph[b].insert(a);
  }

  std::vector<bool> used(n, false);
  std::vector<int> res;
  dfs(graph, used, res, 0, -1);

  for (int i = 0; i < (int)res.size() - 1; ++i) {
    std::cout << res[i] + 1;
    if (i < (int)res.size() - 2) std::cout << " ";
  }
  std::cout << std::endl;
  return 0;  
}
