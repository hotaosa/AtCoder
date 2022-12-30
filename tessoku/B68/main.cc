#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
constexpr int INF = 1 << 30;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  int offset = 0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    offset += max(0, p[i]);
  }

  atcoder::mf_graph<int> graph(n + 2);
  for (int i = 0; i < n; ++i) {
    graph.add_edge(n, i, max(0, p[i]));
    graph.add_edge(i, n + 1, max(0, -p[i]));
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    graph.add_edge(--a, --b, INF);
  }

  cout << offset - graph.flow(n, n + 1) << endl;
  return 0;
}
