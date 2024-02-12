#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <stack>
#include <vector>
//
#include <atcoder/modint>
#include <atcoder/segtree>

using namespace std;
using mint = atcoder::modint998244353;
istream &operator>>(istream &is, mint &m) {
  long long in;
  is >> in;
  m = in;
  return is;
}
ostream &operator<<(ostream &os, const mint &m) {
  os << m.val();
  return os;
}

pair<int, int> Operate(pair<int, int> a, pair<int, int> b) { return min(a, b); }
pair<int, int> E() { return make_pair(1 << 30, 1 << 30); }
using RangeMin = atcoder::segtree<pair<int, int>, Operate, E>;

class VirtualTree {
 public:
  VirtualTree(const vector<vector<int> > &graph, int root = 0)
      : size_(graph.size()),
        graph_(graph),
        in_(vector<int>(size_)),
        out_(vector<int>(size_)) {
    EulerTour(root, -1, 0);
    seg_ = RangeMin(steps_);
  }

  pair<vector<vector<int> >, vector<int> > GetTree(vector<int> nodes) {
    int n = nodes.size();
    sort(nodes.begin(), nodes.end(),
         [&](int i, int j) { return in_[i] < in_[j]; });
    for (int i = 1; i < n; ++i) {
      nodes.emplace_back(LCA(nodes[i], nodes[i - 1]));
    }
    sort(nodes.begin(), nodes.end(),
         [&](int i, int j) { return in_[i] < in_[j]; });
    nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
    n = nodes.size();

    vector<vector<int> > tree(n);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
      int v = nodes[i];
      while (!st.empty() && out_[nodes[st.top()]] < in_[v]) st.pop();
      if (!st.empty()) {
        tree[st.top()].emplace_back(i);
        tree[i].emplace_back(st.top());
      }
      st.push(i);
    }

    return make_pair(tree, nodes);
  }

 private:
  void EulerTour(const int &v, const int &p, const int &depth) {
    in_[v] = steps_.size();
    steps_.emplace_back(depth, v);
    for (int nv : graph_[v]) {
      if (nv == p) continue;
      EulerTour(nv, v, depth + 1);
      steps_.emplace_back(depth, v);
    }
    out_[v] = steps_.size();
  }

  int LCA(const int &u, const int &v) const {
    int l = min(in_[u], in_[v]);
    int r = max(out_[u], out_[v]);
    return seg_.prod(l, r).second;
  }

  int LCA(const vector<int> &nodes) const {
    int l = 1 << 30, r = -1;
    for (const auto v : nodes) {
      l = min(l, in_[v]);
      r = max(r, out_[v]);
    }
    return seg_.prod(l, r).second;
  }

  int size_;
  vector<vector<int> > graph_;
  vector<int> in_, out_;
  vector<pair<int, int> > steps_;
  RangeMin seg_;
};

mint Solve(const vector<vector<int> > &graph, const vector<int> &a, int c) {
  const int n = graph.size();
  vector<mint> dp(n);
  mint res = 0;
  auto DFS = [&](auto DFS, int v, int p) -> void {
    mint prod = 1, sum = 0;
    for (int nv : graph[v]) {
      if (nv == p) continue;
      DFS(DFS, nv, v);
      prod *= dp[nv] + 1;
      sum += dp[nv];
    }
    if (a[v] == c) {
      res += prod;
      dp[v] = prod;
    } else {
      res += prod - sum - 1;
      dp[v] = prod - 1;
    }
  };
  DFS(DFS, 0, -1);
  return res;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  vector<vector<int> > al(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    al[--a[i]].emplace_back(i);
  }

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  VirtualTree vt(graph);
  mint res = 0;
  for (int i = 0; i < n; ++i) {
    if (al[i].size() <= 1) {
      res += al[i].size();
      continue;
    }
    auto [g, id] = vt.GetTree(al[i]);
    vector<int> col(g.size());
    for (int i = 0; i < (int)g.size(); ++i) {
      col[i] = a[id[i]];
    }
    res += Solve(g, col, i);
  }

  cout << res << endl;
  return 0;
}