#include <bits/stdc++.h>

const long long INF = 1LL << 60;

struct Edge {
  int to;
  long long c, d;
  Edge(int to_, long long c_, long long d_) : to(to_), c(c_), d(d_) {}
};

using Graph = std::vector<std::vector<Edge>>;

template<class T> bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  Graph G(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    --a;
    --b;
    G[a].push_back(Edge(b, c, d));
    G[b].push_back(Edge(a, c, d));
  }

  std::vector<long long> dist(n, INF);
  dist[0] = 0;

  std::priority_queue<std::pair<long long, int>,
                      std::vector<std::pair<long long, int>>,
                      std::greater<std::pair<long long, int>>> que;
  que.push(std::make_pair(dist[0], 0));

  while (!que.empty()) {
    int v = que.top().second;
    long long di = que.top().first;
    que.pop();

    if (di > dist[v]) continue;
    for (auto e : G[v]) {
      long long t1 = std::max((long long)std::floor(std::sqrt(e.d) - 1.0), 0LL);
      long long t2 = t1 + 1LL;
      long long t = (t1 + e.d / (t1 + 1) < t2 + e.d / (t2 + 1) ? t1 : t2);
      t = std::max(dist[v], t);
      if (chmin(dist[e.to], t + e.c + e.d / (t + 1))) {
        que.push(std::make_pair(dist[e.to], e.to));
      }
    }
  }

  std::cout << (dist[n - 1] < INF ? dist[n - 1] : -1) << std::endl;
  return 0;
 }
