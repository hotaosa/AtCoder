#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > graph(n);
  std::vector<std::vector<int> > edgenum(n, std::vector<int>(n, -1));
  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    graph[--a].push_back(--b);
    edgenum[a][b] = i;
  }

  std::vector<int> dist(n, -1);
  dist[0] = 0;
  std::vector<std::vector<int> > route(n);
  std::queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        route[nv] = route[v];
        route[nv].push_back(edgenum[v][nv]);
        que.push(nv);
      }
    }
  }
  std::sort(route[n - 1].begin(), route[n - 1].end());
  for (int i = 0; i < m; ++i) {
    if (std::binary_search(route[n - 1].begin(), route[n - 1].end(), i)) {
      std::vector<int> dist2(n, -1);
      dist2[0] = 0;
      std::queue<int> que2;
      que2.push(0);
      while (!que2.empty()) {
        int v = que2.front();
        que2.pop();
        for (int nv : graph[v]) {
          if (edgenum[v][nv] == i) continue;
          if (dist2[nv] == -1) {
            dist2[nv] = dist2[v] + 1;
            que2.push(nv);
          }
        }
      }
      std::cout << dist2[n - 1] << std::endl;
    } else {
      std::cout << dist[n - 1] << std::endl;
    }
  }
  return 0;
}
