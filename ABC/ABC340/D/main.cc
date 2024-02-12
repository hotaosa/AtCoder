#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll INF = 1LL << 60;
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
  ll w;
  Edge(const int &src, const int &to, const ll &w) : src(src), to(to), w(w) {}
  Edge(const int &to, const ll w) : src(-1), to(to), w(w) {}
  Edge(const int &to) : src(-1), to(to), w(1) {}
  bool operator<(const Edge &other) const {
    if (w != other.w) return w < other.w;
    return make_pair(src, to) < make_pair(other.src, other.to);
  }
};
vector<ll> Dijcstra(const vector<vector<Edge> > &graph, const int &s) {
  const int n = graph.size();
  vector<ll> dist(n, INF);
  dist[s] = 0;

  priority_queue<pair<ll, int>, vector<pair<ll, int> >,
                 greater<pair<ll, int> > >
      que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    int v = que.top().second;
    ll d = que.top().first;
    que.pop();
    if (d > dist[v]) continue;
    for (auto e : graph[v])
      if (ChangeMin(dist[e.to], dist[v] + e.w))
        que.push(make_pair(dist[e.to], e.to));
  }
  return dist;
}

int main() {
  int n;
  cin >> n;
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    ll a, b;
    int x;
    cin >> a >> b >> x;
    graph[i].emplace_back(i + 1, a);
    graph[i].emplace_back(--x, b);
  }

  cout << Dijcstra(graph, 0)[n - 1] << endl;
  return 0;
}