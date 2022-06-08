#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr long long INF = 1LL << 60;

struct Edge {
  int id, to;
  long long w;
  Edge (int id_, int to_, long long w_) : id(id_), to(to_), w(w_) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    cin >> a >> b >> c;
    graph[--a].emplace_back(i + 1, --b, c);
    graph[b].emplace_back(i + 1, a, c);
  }

  vector<int> res;
  vector<long long> dist(n, INF);
  dist[0] = 0;
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, greater<> > pque;
  pque.emplace(0, 0, -1);

  while (!pque.empty()) {
    long long d = get<0>(pque.top());
    int v = get<1>(pque.top());
    int edge_id = get<2>(pque.top());
    pque.pop();
    if (d > dist[v]) continue;
    if (edge_id != -1) res.emplace_back(edge_id);
    for (auto e : graph[v]) {
      if (chmin(dist[e.to], d + e.w)) pque.emplace(dist[e.to], e.to, e.id);
    }
  }  
  
  for (auto &p : res) cout << p << " ";
  cout << endl;
  return 0;
}
