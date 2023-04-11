#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &p : a) {
    cin >> p;
    --p;
  }

  atcoder::scc_graph graph(n);
  for (int i = 0; i < n; ++i) {
    graph.add_edge(i, a[i]);
  }

  int res = 0;
  auto scc = graph.scc();
  for (const auto &v : scc) {
    if (v.size() > 1 || a[v[0]] == v[0]) {
      res += v.size();
    }
  }

  cout << res << endl;
  return 0;
}
