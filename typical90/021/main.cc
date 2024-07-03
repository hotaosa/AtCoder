#include <iostream>
//
#include <atcoder/scc>

using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;

  atcoder::scc_graph graph(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(--a, --b);
  }

  ll res = 0;
  for (auto g : graph.scc()) {
    res += (ll)size(g) * (size(g) - 1) / 2;
  }

  cout << res << endl;
  return 0;
}