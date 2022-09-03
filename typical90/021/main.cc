#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::scc_graph graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    graph.add_edge(--u, --v);
  }

  auto scc = graph.scc();
  long long res = 0;
  for (auto v : scc) {
    long long siz = v.size();
    res += siz * (siz - 1) / 2;
  }
  cout << res << endl;  
  return 0;
}
