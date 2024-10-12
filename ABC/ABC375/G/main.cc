#include <iostream>
#include <queue>
#include <utility>
#include <vector>

inline bool ChangeMin(long long &a, long long b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

struct Edge {
  int id;
  int to;
  long long w;
};

std::vector<long long> Dijcstra(const std::vector<std::vector<Edge>> &g,
                                int s) {
  const int n = std::size(g);
  std::vector<long long> dist(n, 1LL << 60);
  dist[s] = 0;

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      pque;
  pque.emplace(std::make_pair(dist[s], s));

  while (!pque.empty()) {
    const auto [d, v] = pque.top();
    pque.pop();
    if (d > dist[v]) continue;
    for (const auto &e : g[v]) {
      if (ChangeMin(dist[e.to], dist[v] + e.w)) {
        pque.emplace(std::make_pair(dist[e.to], e.to));
      }
    }
  }

  return dist;
}

// reference: https://ei1333.github.io/library/graph/others/low-link.hpp
class LowLink {
 public:
  using Graph = std::vector<std::vector<Edge>>;
  explicit LowLink(const Graph &g) : g_(g) {
    ord_.assign(std::size(g), 0);
    low_.assign(std::size(g), 0);
    used_.assign(std::size(g), false);
    int k = 0;
    for (std::size_t i = 0; i < std::size(g); ++i) {
      if (!used_[i]) k = Dfs(i, k, -1);
    }
  }

  std::vector<Edge> Bridges() const { return bridges_; }
  std::vector<int> Articulations() const { return articulations_; }

 private:
  int Dfs(int idx, int k, int par) {
    used_[idx] = true;
    ord_[idx] = low_[idx] = k++;
    bool is_art = false;
    bool beet = false;
    int cnt = 0;
    for (auto &e : g_[idx]) {
      if (e.to == par && !std::exchange(beet, true)) continue;
      if (!used_[e.to]) {
        ++cnt;
        k = Dfs(e.to, k, idx);
        low_[idx] = std::min(low_[idx], low_[e.to]);
        is_art |= par >= 0 && low_[e.to] >= ord_[idx];
        if (ord_[idx] < low_[e.to]) bridges_.emplace_back(e);
      } else {
        low_[idx] = std::min(low_[idx], ord_[e.to]);
      }
    }
    is_art |= par == -1 && cnt > 1;
    if (is_art) articulations_.emplace_back(idx);
    return k;
  }

  const Graph g_;
  std::vector<int> ord_;
  std::vector<int> low_;
  std::vector<int> art_;
  std::vector<bool> used_;
  std::vector<Edge> bridges_;
  std::vector<int> articulations_;
};

int main() {
  std::size_t n, m;
  std::cin >> n >> m;

  std::vector<std::vector<Edge>> g1(n);
  for (std::size_t i = 0; i < m; ++i) {
    int a, b;
    long long c;
    std::cin >> a >> b >> c;
    g1[--a].emplace_back(i, --b, c);
    g1[b].emplace_back(i, a, c);
  }

  const auto d1 = Dijcstra(g1, 0);
  const auto d2 = Dijcstra(g1, n - 1);

  std::vector<std::vector<Edge>> g2(n);
  for (std::size_t u = 0; u < n; ++u) {
    for (const auto &e : g1[u]) {
      std::size_t v = e.to;
      if (d1[u] + e.w + d2[v] == d1[n - 1] ||
          d1[v] + e.w + d2[u] == d1[n - 1]) {
        g2[u].emplace_back(e);
      }
    }
  }

  std::vector<bool> res(m, false);
  for (const auto &e : LowLink(g2).Bridges()) {
    res[e.id] = true;
  }

  for (std::size_t i = 0; i < m; ++i) {
    std::cout << (res[i] ? "Yes" : "No") << "\n";
  }

  return 0;
}