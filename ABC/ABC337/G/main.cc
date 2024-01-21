#include <iostream>
#include <vector>

#include <atcoder/fenwicktree>

using namespace std;

vector<long long> TreeInversion(const vector<vector<int> > &graph) {
  const int n = graph.size();
  vector<long long> ret(n), cnt_sub(n);
  vector<vector<long long> > cnt_sub_edge(n);

  atcoder::fenwick_tree<long long> ft(n);

  auto DFS1 = [&](auto DFS1, int v, int p) -> void {
    ft.add(v, 1);
    for (int nv : graph[v]) {
      cnt_sub_edge[v].emplace_back(0);
      if (nv == p) continue;
      cnt_sub_edge[v].back() -= ft.sum(0, v);
      DFS1(DFS1, nv, v);
      cnt_sub_edge[v].back() += ft.sum(0, v);
    }
    cnt_sub[v] = accumulate(cnt_sub_edge[v].begin(), cnt_sub_edge[v].end(), 0LL);
  };

  auto DFS2 = [&](auto DFS2, int v, int p, long long cur) -> void {
    ret[v] = cur;
    for (int i = 0; i < (int)graph[v].size(); ++i) {
      int nv = graph[v][i];
      if (nv == p) continue;
      long long nx = cur;
      nx -= cnt_sub_edge[v][i];
      nx += nv - cnt_sub[nv];
      DFS2(DFS2, nv, v, nx);
    }
  };

  DFS1(DFS1, 0, -1);
  DFS2(DFS2, 0, -1, accumulate(cnt_sub.begin(), cnt_sub.end(), 0LL));

  return ret;
}

int main() {
  int n;
  cin >> n;

  vector<vector<int> > graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[--u].emplace_back(--v);
    graph[v].emplace_back(u);
  }

  auto cnt_sub = TreeInversion(graph);
  for (auto r : cnt_sub) cout << r << " ";
  cout << endl;

  return 0;
}