#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int SubtreeSize(const std::vector<std::vector<int> > &graph, const int &v, const int &parent) {
  if ((int)graph[v].size() == 1 && graph[v][0] == parent) return 1;
  int ret = 1;
  for (int child : graph[v]) {
    if (child != parent) ret += SubtreeSize(graph, child, v);
  }
  return ret;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  std::vector<int> subtree_sizes;
  for (int child : graph[0]) {
    subtree_sizes.emplace_back(SubtreeSize(graph, child, 0));
  }
  std::sort(subtree_sizes.begin(), subtree_sizes.end());
  int res = std::accumulate(subtree_sizes.begin(), std::prev(subtree_sizes.end()), 1);
  std::cout << res << std::endl;
  return 0;
}