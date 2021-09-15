#include <iostream>
#include <vector>
#include <queue>

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int> > graph(n + m);
  for (int i = 0; i < m; ++i) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; ++j) {
      int r;
      std::cin >> r;
      --r;
      graph[n + i].push_back(r);
      graph[r].push_back(n + i);
    }
  }

  std::vector<int> dist(n + m, -2);
  dist[0] = 0;
  std::queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] >= 0) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }

  for (int i = 0; i < n; ++i) std::cout << dist[i] / 2 << std::endl;
  return 0;  
}
