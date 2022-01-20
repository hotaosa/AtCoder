#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

struct Edge {
  int to, id;
  Edge(int to_, int id_) : to(to_), id(id_) { }
};

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) { cin >> p[i]; --p[i]; }
  int m;
  cin >> m;
  atcoder::dsu uf(n);
  vector<vector<Edge> > graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (uf.same(a, b)) continue;
    uf.merge(a, b);
    graph[a].emplace_back(b, i + 1);
    graph[b].emplace_back(a, i + 1);
  }

  vector<int> res;

  for (int i = 0; i < n; ++i) {
    if (uf.leader(i) == i) {
      auto get = [&](auto get, int v, int tg, int par = -1) -> bool {
        if (p[v] == tg) return true;
        for (auto e : graph[v]) {
          if (e.to == par) continue;          
          if (get(get, e.to, tg, v)) {
            res.push_back(e.id);
            swap(p[v], p[e.to]);
            return true;
          }
        }
        return false;
      };
      auto dfs = [&](auto &dfs, int v, int par = -1) -> bool {
        for (auto e : graph[v]) {
          if (e.to == par) continue;
          if (!dfs(dfs, e.to, v)) return false;
        }
        if (!get(get, v, v)) return false;
        return true;
      };
      if (!dfs(dfs, i)) { cout << "-1" << endl; return 0; }
    }
  }

  cout << res.size() << endl;
  for (int i = 0; i < (int)res.size(); ++i) cout << res[i] << " ";
  cout << endl;  
  return 0;
}
