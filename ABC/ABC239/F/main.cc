#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> d(n);
  for (auto &p : d) cin >> p;

  atcoder::dsu uf(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    uf.merge(--u, --v);
    if (--d[u] < 0 || --d[v] < 0) { cout << "-1" << endl; return 0;}
  }

  vector<vector<int> > connectable(n);
  for (int i = 0; i < n; ++i) for (int j = 0; j < d[i]; ++j)  connectable[uf.leader(i)].push_back(i);

  vector<int> c1;
  vector<vector<int> > c2;

  for (int i = 0; i < n; ++i) {
    if (connectable[i].size() == 1) c1.push_back(connectable[i][0]);
    else if (connectable[i].size() > 1) c2.push_back(connectable[i]);
  }

  vector<pair<int, int> > res;
  for (auto &c : c2) {
    while (c.size() > 1) {
      if (c1.empty()) { cout << "-1" << endl; return 0; }
      uf.merge(c.back(), c1.back());
      res.emplace_back(c.back() + 1, c1.back() + 1);
      c.pop_back();
      c1.pop_back();
    }
    c1.push_back(c.back());    
  }

  if (c1.size() != 2) { cout << "-1" << endl; return 0; }
  uf.merge(c1[0], c1[1]);
  res.emplace_back(c1[0] + 1, c1[1] + 1);
  if (uf.size(0) < n) { cout << "-1" << endl; return 0; }
  for (auto p : res) cout << p.first << " " << p.second << endl;
  return 0;
}
