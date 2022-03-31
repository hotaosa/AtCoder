#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  int to, cost;
  long long time;
  Edge(int to_, int cost_, long long time_) : to(to_), cost(cost_), time(time_) { }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) { a = b; return true; }
  return false;
}

int main() {
  int n, m, s;  
  cin >> n >> m >> s;
  vector<vector<Edge> > graph(n);

  int a_max = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, a;
    long long b;    
    cin >> u >> v >> a >> b;
    chmax(a_max, a);
    graph[--u].emplace_back(--v, a, b);
    graph[v].emplace_back(u, a, b);
  }
  vector<int> c(n);
  vector<long long> d(n);
  for (int i = 0; i < n; ++i) cin >> c[i] >> d[i];

  vector<vector<long long> > dist(n, vector<long long>(a_max * n + 1, INF));
  chmin(s, a_max * n);

  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int> >, greater<tuple<long long, int, int> > > pque;
  pque.emplace(0, 0, s);

  while (!pque.empty()) {
    long long t = get<0>(pque.top());
    int v = get<1>(pque.top());
    int coin = get<2>(pque.top());
    pque.pop();
    if (t > dist[v][coin]) continue;

    for (int i = 1; coin + c[v] * i < (int)dist[v].size(); ++i) {
      if (chmin(dist[v][coin + c[v] * i], t + d[v] * i)) pque.emplace(t + d[v] * i, v, coin + c[v] * i);
    }

    for (auto e : graph[v]) {
      if (coin < e.cost) continue;
      if (chmin(dist[e.to][coin - e.cost], t + e.time)) pque.emplace(t + e.time, e.to, coin - e.cost);
    }
  }

  for (int i = 1; i < n; ++i) {
    long long res = INF;
    for (auto r : dist[i]) chmin(res, r);
    cout << res << endl;
  }
  return 0;
}
