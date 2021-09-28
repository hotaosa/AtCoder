#include <iostream>
#include <vector>
#include <queue>

int dfs(const std::vector<std::vector<int> > &graph, std::vector<int> &siz, int v, int par) {
  if (siz[v] != -1) return siz[v];
  int res = 1;
  for (int nv : graph[v]) {
    if (nv == par) continue;
    res += dfs(graph, siz, nv, v);
  }
  return siz[v] = res;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    std::cin >> u >> v;
    graph[--u].push_back(--v);
    graph[v].push_back(u);
  }

  std::vector<int> dist(n, -1), siz(n, -1);
  dist[0] = 0;
  
  long long sum = 0;
  std::queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (dist[nv] == -1) {
        dist[nv] = dist[v] + 1;
        sum += dist[nv];
        que.push(nv);
      }
    }
  }

  dfs(graph, siz, 0, -1);

  std::vector<long long> res(n, -1);
  res[0] = sum;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : graph[v]) {
      if (res[nv] == -1) {
        res[nv] = res[v] + n - 2 * siz[nv];
        que.push(nv);
      }
    }
  }

  for (int i = 0; i < n; ++i) std::cout << res[i] << std::endl;
  return 0;
}
