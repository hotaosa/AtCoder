#include <iostream>
#include <vector>

using namespace std;
constexpr long long INF = 1LL << 30;

struct Edge {
  int to;
  long long w;
  Edge(int to_, long long w_) : to(to_), w(w_) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

long long solve(const vector<vector<Edge> > &graph) {
  int n = graph.size();
  vector<long long> dist(n, INF);
  dist[0] = 0;
  for (int iter = 0; iter < n; ++iter) {
    for (int v = 0; v < n; ++v) {
      if (dist[v] < INF) for (auto e : graph[v]) chmin(dist[e.to], dist[v] + e.w);
    }
  }

  
  for (int iter = 0; iter < n; ++iter) {
    for (int v = 0; v < n; ++v) {
      if (dist[v] == INF) continue;
      for (auto e : graph[v]) if (chmin(dist[e.to], dist[v] + e.w)) dist[e.to] = -INF;
    }
  }
  long long res = dist[n - 1];
  if (res <= -INF) return -1;
  else return max(0LL, -res);  
}

int main() {
  int n, m;
  long long p;
  cin >> n >> m >> p;
  vector<vector<Edge> > graph(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    graph[--a].emplace_back(--b, p - c);
  }

  cout << solve(graph) << endl;
  return 0;
}