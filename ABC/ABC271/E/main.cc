#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  int from, to;
  long long w;
  Edge(int from, int to, long long w) : from(from), to(to), w(w) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    edges.emplace_back(--u, --v, w);
  }

  vector<long long> dist(n, INF);
  dist[0] = 0;

  for (int i = 0; i < k; ++i) {
    int e;
    cin >> e;
    --e;
    chmin(dist[edges[e].to], dist[edges[e].from] + edges[e].w);
  }

  cout << (dist[n - 1] < INF ? dist[n - 1] : -1) << endl;  
  return 0;
}
