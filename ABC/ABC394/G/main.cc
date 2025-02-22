#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
//
#include <atcoder/dsu>
#include <atcoder/segtree>

class HeavyLightDecomposition {
 public:
  HeavyLightDecomposition(const std::vector<std::vector<int>> &graph,
                          int root = 0)
      : root_(root),
        graph_(graph),
        sz_(std::size(graph)),
        in_(std::size(graph)),
        out_(std::size(graph)),
        head_(std::size(graph)),
        rev_(std::size(graph)),
        par_(std::size(graph)),
        depth_(std::size(graph)) {
    Build();
  }

  int Depth(int v) const { return depth_[v]; }

  int LevelAncestor(int v, int k) const {
    assert(v >= 0 && v < static_cast<int>(std::size(graph_)));
    if (depth_[v] < k) return -1;
    while (in_[v] - k < in_[head_[v]]) {
      k -= in_[v] - in_[head_[v]] + 1;
      v = par_[head_[v]];
    }
    return rev_[in_[v] - k];
  }

  int LowestCommonAncestor(int u, int v) const {
    assert(u >= 0 && u < static_cast<int>(std::size(graph_)));
    assert(v >= 0 && v < static_cast<int>(std::size(graph_)));

    if (in_[u] > in_[v]) std::swap(u, v);
    while (head_[u] != head_[v]) {
      v = par_[head_[v]];
      if (in_[u] > in_[v]) std::swap(u, v);
    }
    return u;
  }

  int Distance(int u, int v) const {
    assert(u >= 0 && u < static_cast<int>(std::size(graph_)));
    assert(v >= 0 && v < static_cast<int>(std::size(graph_)));
    return depth_[u] + depth_[v] - 2 * depth_[LowestCommonAncestor(u, v)];
  }

  bool OnPath(int u, int v, int w) const {
    assert(u >= 0 && u < static_cast<int>(std::size(graph_)));
    assert(v >= 0 && v < static_cast<int>(std::size(graph_)));
    assert(w >= 0 && w < static_cast<int>(std::size(graph_)));
    return Distance(u, w) + Distance(w, v) == Distance(u, v);
  }

  std::vector<std::pair<int, int>> Query(int u, int v, bool edge = false) {
    assert(u >= 0 && u <= static_cast<int>(std::size(graph_)));
    assert(v >= 0 && v <= static_cast<int>(std::size(graph_)));

    std::vector<std::pair<int, int>> ret;
    while (true) {
      if (in_[u] > in_[v]) std::swap(u, v);
      if (head_[u] == head_[v]) break;
      ret.emplace_back(in_[head_[v]], in_[v] + 1);
      v = par_[head_[v]];
    }
    ret.emplace_back(in_[u] + edge, in_[v] + 1);
    return ret;
  }

  std::pair<int, int> SubtreeQuery(int v, bool edge = false) const {
    assert(v >= 0 && v < static_cast<int>(std::size(graph_)));
    return {in_[v] + edge, out_[v]};
  }

  int Index(int u, int v = -1) {
    if (v != -1) return std::max(in_[u], in_[v]);
    return in_[u];
  }

 private:
  void Build() {
    head_[root_] = root_;
    DFS(root_, -1, 0);
    int c = 0;
    Decomposition(root_, -1, &c);
  }

  void DFS(int v, int p, int d) {
    par_[v] = p;
    sz_[v] = 1;
    depth_[v] = d;
    if (!graph_[v].empty() && graph_[v][0] == p) {
      std::swap(graph_[v][0], graph_[v].back());
    }
    for (auto &nv : graph_[v]) {
      if (nv == p) continue;
      DFS(nv, v, d + 1);
      sz_[v] += sz_[nv];
      if (sz_[graph_[v][0]] < sz_[nv]) std::swap(graph_[v][0], nv);
    }
  }

  void Decomposition(int v, int p, int *cnt) {
    in_[v] = (*cnt)++;
    rev_[in_[v]] = v;
    for (const auto &nv : graph_[v]) {
      if (nv == p) continue;
      head_[nv] = (graph_[v][0] == nv ? head_[v] : nv);
      Decomposition(nv, v, cnt);
    }
    out_[v] = *cnt;
  }

  const int root_;
  std::vector<std::vector<int>> graph_;
  std::vector<int> sz_;
  std::vector<int> in_;
  std::vector<int> out_;
  std::vector<int> head_;
  std::vector<int> rev_;
  std::vector<int> par_;
  std::vector<int> depth_;
};

struct Edge {
  int u, v, w;
  bool operator<(const Edge &other) const { return w < other.w; }
};

int Min(int a, int b) { return a < b ? a : b; }
int Inf() { return 1 << 30; }

int main() {
  int h, w;
  std::cin >> h >> w;
  int n = h * w;

  std::vector<int> hight(n);
  for (int i = 0; i < n; ++i) std::cin >> hight[i];

  std::vector<Edge> edges;
  for (int i = 0; i < n; ++i) {
    if (i / w > 0) {
      edges.emplace_back(i, i - w, std::min(hight[i], hight[i - w]));
    }
    if (i / w < h - 1) {
      edges.emplace_back(i, i + w, std::min(hight[i], hight[i + w]));
    }
    if (i % w > 0) {
      edges.emplace_back(i, i - 1, std::min(hight[i], hight[i - 1]));
    }
    if (i % w < w - 1) {
      edges.emplace_back(i, i + 1, std::min(hight[i], hight[i + 1]));
    }
  }
  std::sort(edges.rbegin(), edges.rend());

  std::vector graph(n, std::vector<int>{});
  atcoder::dsu uf(n);
  for (auto e : edges) {
    if (!uf.same(e.u, e.v)) {
      graph[e.u].emplace_back(e.v);
      graph[e.v].emplace_back(e.u);
      uf.merge(e.u, e.v);
    }
  }

  auto hld = HeavyLightDecomposition(graph);
  atcoder::segtree<int, Min, Inf> seg(n);
  for (int i = 0; i < n; ++i) seg.set(hld.Index(i), hight[i]);

  int q;
  std::cin >> q;
  while (q--) {
    int a, b, y, c, d, z;
    std::cin >> a >> b >> y >> c >> d >> z;
    int u = --a * w + --b;
    int v = --c * w + --d;

    int m = Inf();
    for (auto [l, r] : hld.Query(u, v)) {
      m = Min(m, seg.prod(l, r));
    }

    int res = y > m ? y - m + std::abs(z - m) : std::abs(z - y);
    std::cout << res << "\n";
  }

  return 0;
}