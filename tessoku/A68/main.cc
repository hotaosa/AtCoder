#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::mf_graph<int> graph(n);
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    graph.add_edge(--u, --v, c);
  }

  cout << graph.flow(0, n - 1) << endl;  
  return 0;
}
