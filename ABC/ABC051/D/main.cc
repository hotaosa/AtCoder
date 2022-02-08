#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 29;

struct Edge {
  int src, to;
  int w;
  Edge(int src_, int to_, int w_) : src(src_), to(to_), w(w_) { }
  Edge(int to_, int w_) : src(-1), to(to_), w(w_) { }
  Edge(int to_) : src(-1), to(to_), w(1) { }
  bool operator<(const Edge other) const { return w < other.w; }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<vector<int> > warshall_floyd(const vector<vector<Edge> > &graph) {
  int n = graph.size();
  vector<vector<int> > dist(n, vector<int>(n, INF));
  for (int v = 0; v < n; ++v) {
    dist[v][v] = 0;
    for (auto e : graph[v]) dist[v][e.to] = e.w;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return dist;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge> > graph(n);
  vector<Edge> ve;
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    --a;
    --b;
    ve.emplace_back(a, b, c);  
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, c);
  }
  
  vector<vector<int> > dist = warshall_floyd(graph);    
  int res = 0;
  for (int i = 0; i < m; ++i) {
    if (dist[ve[i].src][ve[i].to] < ve[i].w) ++res;
  }
  cout << res << endl;  
  return 0;  
}
