#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].emplace_back(--b);
  }

  std::vector<int> dist(n, -1);
  std::queue<int> que;
  for (int v : graph[0]) {
    dist[v] = 1;
    que.emplace(v);
  }

  while (!std::empty(que)) {
    int u = que.front();
    que.pop();
    for (int v : graph[u]) {
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        que.emplace(v);
      }
    }
  }

  std::cout << dist[0] << "\n";
  return 0;
}