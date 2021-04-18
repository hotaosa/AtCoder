#include <iostream>
#include <vector>

struct Edge {
  int to;
  int c;
  Edge(int to, int c) : to(to), c(c) {};
};

void dfs(const std::vector<std::vector<Edge>> &graph, std::vector<int> &color, int v) {
  int n = graph.size();
  for (Edge e : graph[v]) {
    if (color[e.to]) continue;
    if (e.c == color[v]) color[e.to] = (color[v] + 1) % n + 1;
    else color[e.to] = e.c;
    dfs(graph, color, e.to);
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<Edge>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    std::cin >> a >> b >> c;
    --a; --b;
    graph[a].push_back(Edge(b, c));
    graph[b].push_back(Edge(a, c));
  }

  std::vector<int> color(n, 0);
  color[0] = 1;
  dfs(graph, color, 0);

  for (int res : color) std::cout << res << std::endl;
  return 0;  
}
