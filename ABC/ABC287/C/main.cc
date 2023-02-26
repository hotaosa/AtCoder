#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

bool Solve() {
  int n, m;
  cin >> n >> m;
  if (m != n - 1) return false;

  atcoder::dsu uf(n);
  vector<int> deg(n, 0);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    uf.merge(--u, --v);
    ++deg[u];
    ++deg[v];
  }
  auto g = uf.groups();
  if (g.size() != 1) return false;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 1) ++cnt;
  }
  return cnt == 2;
}

int main() {
  cout << (Solve() ? "Yes" : "No" ) << endl;
  return 0;
}
