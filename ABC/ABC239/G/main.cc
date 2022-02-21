#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

constexpr long long INF = 1LL << 60;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> u(m), v(m);
  for (int i = 0; i < m; ++i) {
    cin >> u[i] >> v[i];
    --u[i];
    --v[i];
  }

  vector<long long> c(n);
  for (auto &p : c) cin >> p;

  atcoder::mf_graph<long long> graph(n * 2);
  for (int i = 1; i < n - 1; ++i) graph.add_edge(i, i + n, c[i]);
  for (int i = 0; i < m; ++i) {
    graph.add_edge(u[i] + n, v[i], INF);
    graph.add_edge(v[i] + n, u[i], INF);
  }

  cout << graph.flow(n, n - 1) << endl;
  auto vb = graph.min_cut(n);
  int cnt = 0;
  for (int i = 1; i < n - 1; ++i) if (vb[i] ^ vb[i + n]) ++cnt;
  cout << cnt << endl;
  for (int i = 1; i < n - 1; ++i) if (vb[i] ^ vb[i + n]) cout << i + 1 << " ";
  cout << endl;  
  return 0;
}
