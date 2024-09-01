#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

struct Edge {
  int to;
  ll w;
  Edge(int to, ll w) : to(to), w(w) {}
};

int main() {
  int n;
  cin >> n;
  vector<vector<Edge>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    graph[--u].emplace_back(--v, l);
    graph[v].emplace_back(u, l);
  }

  vector<ll> subtree_depth(n, 0);
  auto RecordSubtreeDepth = [&](auto self, int v, int par) -> ll {
    for (auto e : graph[v]) {
      if (e.to == par) continue;
      subtree_depth[v] = max(subtree_depth[v], self(self, e.to, v) + e.w);
    }
    return subtree_depth[v];
  };
  RecordSubtreeDepth(RecordSubtreeDepth, 0, -1);

  vector<ll> branch_depth;
  auto RecordBranchDepth = [&](auto self, int v, int par, ll cur) -> void {
    vector<Edge> edges;
    for (auto e : graph[v]) {
      if (e.to != par) edges.emplace_back(e);
    }
    if (empty(edges)) {
      branch_depth.emplace_back(cur);
      return;
    }

    sort(begin(edges), end(edges), [&](Edge e1, Edge e2) {
      return subtree_depth[e1.to] + e1.w > subtree_depth[e2.to] + e2.w;
    });

    self(self, edges[0].to, v, cur + edges[0].w);
    for (size_t i = 1; i < size(edges); ++i) {
      self(self, edges[i].to, v, edges[i].w);
    }
  };
  RecordBranchDepth(RecordBranchDepth, 0, -1, 0);

  sort(rbegin(branch_depth), rend(branch_depth));

  ll res = 0;
  for (int i = 0; i < n; ++i) {
    if (i < (int)size(branch_depth)) {
      res += branch_depth[i] * 2;
    }
    cout << res << endl;
  }

  return 0;
}
