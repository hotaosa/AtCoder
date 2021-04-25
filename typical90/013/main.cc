#include <iostream>
#include <vector>
#include <queue>

struct Edge {
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w) { }
};

using Graph = std::vector<std::vector<Edge>>;

template <typename T> bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  else return false;
}

void dijcstra(const Graph &G, std::vector<long long> &dist, int s) {
  dist[s] = 0LL;
  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>> que;
  que.push(std::make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    long long d = que.top().first;
    que.pop();
    if (d > dist[v]) continue;
    for (auto e : G[v]) {
      if (chmin(dist[e.to], dist[v] + e.w)) que.push(std::make_pair(dist[e.to], e.to));
    }
  }
}

int main() {
  const long long INF = 1LL << 60;
  int n, m;
  std::cin >> n >> m;
  Graph G(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    std::cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(Edge(b, c));
    G[b].push_back(Edge(a, c));    
  }

  std::vector<long long> dist1(n, INF), dist2(n, INF);
  dijcstra(G, dist1, 0);
  dijcstra(G, dist2, n - 1);

  for (int i = 0; i < n; ++i) {
    std::cout << dist1[i] + dist2[i] << std::endl;
  }
  return 0;
}

