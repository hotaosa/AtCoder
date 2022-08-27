#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int id, to;
  Edge(int id_, int to_) : id(id_), to(to_) { }
};

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m), b(m);
  for (auto &p : a) { cin >> p; --p; }
  for (auto &p : b) { cin >> p; --p; }

  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    graph[a[i]].emplace_back(i, b[i]);
    graph[b[i]].emplace_back(~i, a[i]);
  }

  string res = string(m, '2');
  vector<bool> used(n, false);

  auto dfs = [&](auto dfs, int v, int p = -1) -> void {
    used[v] = true;
    for (auto e : graph[v]) {
      if (e.to == p) continue;
      if (used[e.to]) {
        if (e.id < 0) res[~e.id] = '0';
        else res[e.id] = '1';
      } else {
        if (e.id < 0) res[~e.id] = '1';
        else res[e.id] = '0';
        dfs(dfs, e.to, v);
      }      
    }
  };

  for (int i = 0; i < n; ++i) if (!used[i]) dfs(dfs, i);
  cout << res << endl;
  return 0;
}