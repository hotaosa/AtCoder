#include <cassert>
#include <iostream>
#include <stack>
#include <vector>

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

  int Idx(int u, int v = -1) {
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

int main() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> h(n);
  for (auto &e : h) std::cin >> e;

  std::vector<std::vector<int>> graph(n + 1);
  std::stack<std::pair<int, int>> st({{n + 1, n}});

  for (int i = n - 1; i >= 0; --i) {
    while (st.top().first < h[i]) st.pop();
    graph[i].emplace_back(st.top().second);
    graph[st.top().second].emplace_back(i);
    st.emplace(h[i], i);
  }

  HeavyLightDecomposition hld(graph, n);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    std::cout << hld.Depth(hld.LowestCommonAncestor(l, r)) << "\n";
  }

  return 0;
}