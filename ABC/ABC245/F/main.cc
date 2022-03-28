#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  atcoder::scc_graph sg(n);
  vector<vector<int> > graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;    
    sg.add_edge(--u, --v);
    graph[u].push_back(v);
  }

  auto scc = sg.scc();
  int siz = scc.size();
  vector<bool> possible(n, false);
  int res = 0;

  for (int i = siz - 1; i >= 0; --i) {
    if (scc[i].size() > 1) {
      for (int v : scc[i]) possible[v] = true;
      res += scc[i].size();
    } else {
      int v = scc[i][0];
      for (int nv : graph[v]) if (possible[nv]) possible[v] = true;
      if (possible[v]) ++res;
    }
  }

  cout << res << endl;
  return 0;
}
