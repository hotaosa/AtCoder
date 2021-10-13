#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = 1 << 30;

struct Edge {
  int to, w;
  Edge(int to_, int w_) : to(to_), w(w_) { }
};

bool chmin(int &a, int b) {
  if (a > b) { a = b; return true; }
  else return false;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a;
    --b;
    graph[a].push_back(Edge(b, c));
    graph[b].push_back(Edge(a, c));
  }

  auto dijcstra = [&](int s) -> std::vector<int> {
    std::vector<int> dist(n, INF);
    dist[s] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > que;
    que.push(std::make_pair(0, s));

    while (!que.empty()) {
      int v = que.top().second;
      int d = que.top().first;
      que.pop();
      if (d > dist[v]) continue;

      for (auto e : graph[v]) {
        if (chmin(dist[e.to], dist[v] + e.w)) que.push(std::make_pair(dist[e.to], e.to));
      }
    }
    return dist;
  };

  std::vector<int> dist1 = dijcstra(0), dist2 = dijcstra(n - 1);
  for (int i = 0; i < n; ++i) std::cout << dist1[i] + dist2[i] << std::endl;
  return 0;
}
