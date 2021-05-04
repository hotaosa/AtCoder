#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Edge {
  int to, w;  
  Edge(int to_, int w_) : to(to_), w(w_) {}
};

template<class T> bool chmin(T& a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  const int INF = 1 << 30;
  int r, c;
  std::cin >> r >> c;
  int n = r * c;
  std::vector<std::vector<Edge>> graph(n * 2);
  std::vector<int> a(n, INF), b(n, INF);
  for (int i = 0; i < r; ++i) {
    for (int j = 1; j < c; ++j) std::cin >> a[i * c + j];
  }
  for (int i = 1; i < r; ++i) {
    for (int j = 0; j < c; ++j) std::cin >> b[i * c + j];
  }

  for (int i = 0; i < n; ++i) {
    if (i % c < c - 1) graph[i].push_back(Edge(i + 1, a[i + 1]));
    if (i % c > 0) graph[i].push_back(Edge(i - 1, a[i]));
    if (i / c < r - 1) graph[i].push_back(Edge(i + c, b[i + c]));
    graph[i].push_back(Edge(i + n, 1));
  }
  for (int i = n; i < n * 2; ++i) {
    graph[i].push_back(Edge(i - n, 0));
    if (i >= n + c) graph[i].push_back(Edge(i - c, 1));
  }

  std::vector<int> dist(n * 2, INF);
  dist[0] = 0;

  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> que;
  que.push(std::make_pair(dist[0], 0));

  while (!que.empty()) {
    int v = que.top().second;
    int d = que.top().first;
    que.pop();

    if (d > dist[v]) continue;
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], dist[v] + e.w)) que.push(std::make_pair(dist[e.to], e.to));
    }
  }

  std::cout << dist[n - 1] << std::endl;
  return 0;
 }
