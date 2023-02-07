#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  int to;
  pair<int, long long> w;
  Edge(int to, pair<int, long long> w) : to(to), w(w) { }
};

pair<int, long long> Add(pair<int, long long> a, pair<int, long long> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}

template<class T> inline bool ChangeMin(T &a, const T &b) {
  if (a > b) { a = b; return true; }
  return false;
}

vector<vector<pair<int, long long> > > WarshallFloyd(const vector<vector<Edge> > &graph) {
  const int n = graph.size();
  vector<vector<pair<int, long long>> > dist(n, vector<pair<int, long long>>(n, {n, 0}));
  for (int v = 0; v < n; ++v) {
    dist[v][v] = {0, 0};
    for (auto e : graph[v]) dist[v][e.to] = e.w;
  }
  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ChangeMin(dist[i][j], Add(dist[i][k], dist[k][j]));
      }
    }
  }
  return dist;
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (auto &p : a) cin >> p;

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < n; ++j) {
      if (s[j] == 'Y') graph[i].emplace_back(j, make_pair(1, -a[j]));
    }
  }
  auto dist = WarshallFloyd(graph);
  
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    auto d = dist[--u][--v];
    if (d.first < n) {
      cout << d.first << " " << -d.second + a[u] << endl;
    } else {
      cout << "Impossible" << endl;
    }
  }
  
  return 0;
}
