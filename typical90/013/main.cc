#include <iostream>
#include <queue>
#include <vector>

using namespace std;
constexpr int INF = 1 << 30;

template <class T>
inline bool ChangeMin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

struct Edge {
  int src, to;
  int w;
  Edge(const int &src, const int &to, const int &w) : src(src), to(to), w(w) {}
  Edge(const int &to, const int w) : src(-1), to(to), w(w) {}
  Edge(const int &to) : src(-1), to(to), w(1) {}
  bool operator<(const Edge &other) const {
    if (w != other.w) return w < other.w;
    return make_pair(src, to) < make_pair(other.src, other.to);
  }
};

vector<int> Dijcstra(const vector<vector<Edge>> &graph, const int &s) {
  const int n = graph.size();
  vector<int> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    int d = que.top().first;
    que.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v])
      if (ChangeMin(dist[e.to], dist[v] + e.w))
        que.push(make_pair(dist[e.to], e.to));
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    graph[--a].emplace_back(--b, c);
    graph[b].emplace_back(a, c);
  }

  auto d1 = Dijcstra(graph, 0);
  auto d2 = Dijcstra(graph, n - 1);

  for (int i = 0; i < n; ++i) {
    cout << d1[i] + d2[i] << endl;
  }
  return 0;
}