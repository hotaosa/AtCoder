#include <iostream>
#include <vector>
#include <queue>

struct Edge {
  int to;
  long long w;
  Edge(int to_, long long w_) : to(to_), w(w_) { }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<Edge> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    long long w;
    std::cin >> u >> v >> w;
    --u;
    --v;
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
  }

  std::vector<long long> dist(n, -1LL);
  std::queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (auto nx : graph[v]) {
      if (dist[nx.to] == -1) {
        dist[nx.to] = dist[v] + nx.w;
        que.push(nx.to);
      }
    }
  }

  for (auto d : dist) std::cout << d % 2LL << std::endl;
  return 0;
}
