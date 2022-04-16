#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::scc_graph graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(--a, --b);
  }

  auto scc = graph.scc();
  long long res = 0;
  for (auto v : scc) res += v.size() * (v.size() - 1) / 2;
  cout << res << endl;  
  return 0;
}
