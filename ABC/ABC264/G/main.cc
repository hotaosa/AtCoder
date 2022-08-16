#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr long long INF = 1LL << 50;

struct Edge {
  int src, to;
  long long w;
  Edge(int src_, int to_, long long w_) : src(src_), to(to_), w(w_) { }
  Edge(int to_, long long w_) : src(-1), to(to_), w(w_) { }
  Edge(int to_) : src(-1), to(to_), w(1) { }
  bool operator<(const Edge other) const { return w < other.w; }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

pair<bool, vector<long long> > bellman_ford(const vector<vector<Edge> > &graph, int s) {
  int n = graph.size();
  bool exist_negative_cycle = false;
  vector<long long> dist(n, INF);
  dist[s] = 0;

  for (int iter = 0; iter < n; ++iter) {
    bool update = false;
    for (int v = 0; v < n; ++v) {
      if (dist[v] == INF) continue;
      for (auto e : graph[v]) update |= chmin(dist[e.to], dist[v] + e.w);
    }
    if (!update) break;
    if (iter == n - 1 && update) exist_negative_cycle = true;
  }

  return make_pair(!exist_negative_cycle, dist);
}

int f(int a, int b) { return a * 27 + b; }

int main() {
  long long cost[27][27][27][27];
  for (int i = 0; i < 27; ++i) {
    for (int j = 0; j < 27; ++j) {      
      for (int k = 0; k < 27; ++k) {
        for (int l = 0; l < 27; ++l) {
          cost[i][j][k][l] = INF;
          if (i < 26 && j == 26) continue;
          if (k < 26 && l == 26) continue;
          if (k == j) cost[i][j][k][l] = 0;
        }
      }
    }
  }

  int n;
  cin >> n;
  while (n--) {
    string t;
    long long p;
    cin >> t >> p;
    if (t.size() == 1) {
      for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < 27; ++j) {
          if (i < 26 && j == 26) continue;
          cost[i][j][j][t[0] - 'a'] -= p;
        }
      }
    } else if (t.size() == 2) {
      for (int i = 0; i < 27; ++i) {
        cost[i][t[0] - 'a'][t[0] - 'a'][t[1] - 'a'] -= p;
      } 
    } else {
      cost[t[0] - 'a'][t[1] - 'a'][t[1] - 'a'][t[2] - 'a'] -= p;
    }
  }
  
  vector<vector<Edge> > graph(27 * 27);
  for (int i = 0; i < 27; ++i) {
    for (int j = 0; j < 27; ++j) {
      for (int k = 0; k < 27; ++k) {
        for (int l = 0; l < 27; ++l) {
          if (cost[i][j][k][l] != INF) {
            graph[f(i, j)].emplace_back(f(k, l), cost[i][j][k][l]);
          }
        }
      }
    }
  }

  auto ret = bellman_ford(graph, f(26, 26));
  if (ret.first) {
    long long res = INF;
    for (int i = 0; i < f(26, 26); ++i) chmin(res, ret.second[i]);
    cout << -res << endl;
  } else {
    cout << "Infinity" << endl;
  }  
  return 0;
}
