#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr long long INF = 1LL << 60;

struct Edge {
  int from, to;
  long long w;
  Edge(int from, int to, long long w) : from(from), to(to), w(w) { }
  bool operator<(const Edge &rhs) const { return w < rhs.w; }
};

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) { a = b; return true; }
  return false;
}

long long kruskal(vector<Edge> edges, const int &n) {
  sort(edges.begin(), edges.end());
  atcoder::dsu uf(n);
  long long ret = 0;
  int merge_count = 0;
  for (auto e : edges) {
    if (!uf.same(e.from, e.to)) {
      ret += e.w;
      uf.merge(e.from, e.to);
      ++merge_count;
    }
  }
  if (merge_count < n - 1) return INF;
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> x(n), y(n);
  for (auto &p : x) cin >> p;
  for (auto &p : y) cin >> p;

  vector<Edge> edges;
  for (int i = 0; i < m; ++i) {
    int u, v;
    long long w;
    cin >> u >> v >> w;
    edges.emplace_back(--u, --v, w);
  }

  long long res = kruskal(edges, n);
  for (int i = 0; i < n; ++i) edges.emplace_back(i, n, x[i]);
  chmin(res, kruskal(edges, n + 1));
  for (int i = 0; i < n; ++i) edges.pop_back();
  for (int i = 0; i < n; ++i) edges.emplace_back(i, n, y[i]);
  chmin(res, kruskal(edges, n + 1));
  for (int i = 0; i < n; ++i) edges.emplace_back(i, n + 1, x[i]);
  chmin(res, kruskal(edges, n + 2));

  cout << res << endl;    
  return 0;
}
