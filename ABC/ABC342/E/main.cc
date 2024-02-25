#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using ll = long long;

template <class T>
bool ChangeMax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

struct Edge {
  int to;
  ll l, d, k, c;
  Edge(int to, ll l, ll d, ll k, ll c) : to(to), l(l), d(d), k(k), c(c) {}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge> > graph(n);

  for (int i = 0; i < m; ++i) {
    ll l, d, k, c;
    int u, v;
    cin >> l >> d >> k >> c >> u >> v;
    graph[--v].emplace_back(--u, l, d, k, c);
  }

  vector<ll> dist(n, -1);
  priority_queue<pair<ll, int>, vector<pair<ll, int> > > pque;
  for (auto e : graph[n - 1]) {
    if (ChangeMax(dist[e.to], e.l + (e.k - 1) * e.d)) {
      pque.emplace(dist[e.to], e.to);
    };
  }

  while (!pque.empty()) {
    auto [d, v] = pque.top();
    pque.pop();
    if (d < dist[v]) continue;

    for (auto e : graph[v]) {
      if (e.l + e.c > d) continue;
      if (ChangeMax(dist[e.to], min(e.l + (e.k - 1) * e.d,
                                    e.l + (d - e.c - e.l) / e.d * e.d))) {
        pque.emplace(dist[e.to], e.to);
      }
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    if (dist[i] < 0) {
      cout << "Unreachable\n";
    } else {
      cout << dist[i] << endl;
    }
  }

  return 0;
}