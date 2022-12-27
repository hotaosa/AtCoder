#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  Edge(int to, long long w) : to(to), w(w) { }
  int to;
  long long w;
};

int main() {
  int n, m, q;
  cin >> n >> m >> q;

  atcoder::dsu uf(n);
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    uf.merge(--a, --b);
    graph[a].emplace_back(b, c);
    graph[b].emplace_back(a, -c);
  }

  set<int> root_inf;
  vector<long long> dist(n, INF);

  auto dfs = [&](auto dfs, int v) -> bool {
    for (auto e : graph[v]) {
      if (dist[e.to] < INF) {
        if (dist[v] + e.w != dist[e.to]) {
          root_inf.insert(uf.leader(v));
          return true;
        }
      } else {
        dist[e.to] = dist[v] + e.w;
        if (dfs(dfs, e.to)) return true;
      }
    }
    return false;
  };

  for (int i = 0; i < n; ++i) {
    if (uf.leader(i) == i) {
      dist[i] = 0;
      dfs(dfs, i);
    }
  }
  

  while (q--) {
    int u, v;
    cin >> u >> v;
    if (!uf.same(--u, --v)) {
      cout << "nan" << endl;
    } else if (root_inf.count(uf.leader(u))) {
      cout << "inf" << endl;
    } else {
      cout << dist[v] - dist[u] << endl;
    }    
  }
  
  return 0;
}
